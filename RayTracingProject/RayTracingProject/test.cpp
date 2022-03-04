#include <stdio.h>
#include "FreeImage.h"
#include "Scene.h"
#include "IntersectionChecker.h"

#define WIDTH 800
#define HEIGHT 600
#define Ke 10
#define DEBUG false

int main() {
	
	RGBQUAD color;
	FIBITMAP* image = FreeImage_Allocate(WIDTH, HEIGHT, 32);
	Material* mat1 = new Material(Vec3(0, 255, 0));
	Material* mat2 = new Material(Vec3(255, 0, 0));
	Light light = Light(Vec3(), 0.8, Vec3(150, 150, -100));



	Scene myScene = Scene();
	myScene.activeCam = new Camera(90);
	myScene.activeCam->setFocaleFromScreenSize(WIDTH, HEIGHT);
	myScene.lights.push_back(light);

	myScene.Objects.push_back(new Sphere(Vec3(0, 0, -250), 100));
	myScene.Objects[0]->setMaterial(mat1);
	myScene.Objects.push_back(new Plane(Vec3(-150, 150, -175), 300, 300, Vec3(1, 0, 0), Vec3(0, 1, 0)));
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
				Vec3 normal, viewVec = (view.origin - outputInfos).getNormalized();
				float ia = -0.01, id = 0, is = 0;

				if (Sphere* tmp = dynamic_cast<Sphere*>(firstInSight))
					normal = outputInfos - tmp->position;
				else
					if (Plane* tmp = dynamic_cast<Plane*>(firstInSight))
						normal = tmp->base[0] ^ tmp->base[1];

				normal.normalize();

				for (int z = 0; z < myScene.lights.size(); z++) {
					Light l = myScene.lights[z];
					Vec3 lightVec = (l.position - outputInfos).getNormalized();
					Vec3 h = (lightVec + viewVec) / (lightVec.getLength() + viewVec.getLength());

					if (l.intensity > ia)
						ia = l.intensity;
					id += (mat.diffuse * (normal * lightVec)) / (outputInfos - l.position).getLength();
					is += (mat.specular * powf(normal * h, Ke)) / (outputInfos - l.position).getLength();
				}

				Vec3 pix = mat.color * (mat.ambiance * ia) + mat.color * (mat.diffuse * id) + Vec3(255, 255, 255) * (mat.specular * is);
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