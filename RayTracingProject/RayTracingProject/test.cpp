#include <stdio.h>
#include "FreeImage.h"
#include "Scene.h"
#include "IntersectionChecker.h"

#define WIDTH 800
#define HEIGHT 600
#define DEBUG false

int main() {
	
	RGBQUAD color;
	FIBITMAP* image = FreeImage_Allocate(WIDTH, HEIGHT, 32);
	Material* mat1 = new Material(Vec3(0, 255, 0));
	Material* mat2 = new Material(Vec3(255, 0, 0));
	Light light = Light(Vec3(), 0.8, Vec3(0, 0, -WIDTH * 5));

	Scene myScene = Scene();
	myScene.activeCam = new Camera(90);
	myScene.activeCam->setFocaleFromScreenSize(WIDTH, HEIGHT);
	myScene.Objects.push_back(new Sphere(Vec3(0, 0, -myScene.activeCam->getFocale() - 3), 100));
	myScene.Objects[0]->setMaterial(mat1);
	myScene.Objects.push_back(new Plane(Vec3(-300, 300, -myScene.activeCam->getFocale() + 70), 600, 600, Vec3(1, 0, 0), Vec3(0, 1, 0)));
	myScene.Objects[1]->setMaterial(mat2);

	float foc = myScene.activeCam->getFocale();

	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			color.rgbRed = color.rgbGreen = color.rgbBlue = 0;

			Vec3 target = Vec3(i - WIDTH/2, j - HEIGHT/2, -foc) - myScene.activeCam->position;
			Ray view = { myScene.activeCam->position, target };

			C3DObject* firstInSight = nullptr;
			Vec3 outputInfos;
			float distance = -1;

			for (int k = 0; k < myScene.Objects.size(); k++) {
				C3DObject* obj = myScene.Objects[k];
				Vec3 output;
				float dist;

				if(Sphere* tmp = dynamic_cast<Sphere*>(obj)) {
					if (IntersectionChecker().checkIntersection(view, *tmp, &output, &dist)) {
						if(dist > 0.01 && (distance < -0.01 || dist < distance)){
							distance = dist;
							firstInSight = obj;
							outputInfos = output;
						}
					}
				}else{
					if (Plane* tmp = dynamic_cast<Plane*>(obj)) {
						if (IntersectionChecker().checkIntersection(view, *tmp, &output, &dist)) {
							if (dist > 0.01 && (distance < -0.01 || dist < distance)) {
								distance = dist;
								firstInSight = obj;
								outputInfos = output;
							}
						}
					}else {
						if (Triangle* tmp = dynamic_cast<Triangle*>(obj)) {
							if (IntersectionChecker().checkIntersection(view, *tmp, &output, &dist)) {
								if (dist > 0.01 && (distance < -0.01 || dist < distance)) {
									distance = dist;
									firstInSight = obj;
									outputInfos = output;
								}
							}
						}
					}
				}
			}

			if (firstInSight) {
				Material mat = firstInSight->getMaterial();
				Vec3 pix = mat.color * (mat.ambiance * light.intensity);
				color.rgbRed = pix.x;
				color.rgbGreen = pix.y;
				color.rgbBlue = pix.z;

				FreeImage_SetPixelColor(image, i, j, &color);
			}

			if(DEBUG)
				printf("Pixel (%d,%d) done\n", i, j);
		}
	}

	FreeImage_Save(FIF_BMP, image, "out.bmp");

	delete myScene.activeCam;
	delete mat1;
	delete mat2;
	return 0;
}