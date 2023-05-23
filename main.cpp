#include <GL/glut.h>
#include <math.h>

//float y dan q untuk menginisialisasinya dengan nilai Nilai ini digunakan untuk menggeser kurva vertikal.
float y = -0.4;
float q = 0.1;

//Luka
GLfloat ctrlpoints[4][3] = 
{
    {0.5, -0.02+q, 0.0}, 
    {0.45, -0.07+q, 0.0},
    {0.4, -0.12+q, 0.0},
    {0.25, -0.12+q, 0.0}, 
};


//alis kiri
GLfloat ctrlpoints1[4][3] = 
{
    {-0.4, 0.28+q, 0.0},
    {-0.3, 0.34+q, 0.0},
	{-0.2, 0.39+q, 0.0}, 
    {-0.05, 0.28+q, 0.0},    
};

//alis kanan

GLfloat ctrlpoints2[4][3] = 
{
    {0.42, 0.36+q, 0.0},
    {0.22, 0.34+q, 0.0},
	{0.12, 0.39+q, 0.0}, 
    {0.07, 0.28+q, 0.0},    
};


void display() {
   glClear(GL_COLOR_BUFFER_BIT);

    //Menggambar lingkaran untuk wajah
   glColor3ub(0, 193, 0);
   glBegin(GL_POLYGON);
   
   for(float i = 0; i < 360; i += 1) {
      float x = 0.7 * cos(i * 3.14159 / 180);
      float y = 0.7 * sin(i * 3.14159 / 180);
      glVertex2f(x, y);
   }
   glEnd();
   
//  Menggambar Mata
	float p = 0;
   for(float j=0; j<2; j++){
   	// Menggambar oval untuk mata
   		glColor3f(1.0, 1.0, 1.0);
   		glBegin(GL_TRIANGLE_FAN);
   			for(float i = 0; i < 360; i += 1) {
      		float x = 0.18 * cos(i * 3.14159 / 180) - 0.25 + p;
      		float y = 0.15	 * sin(i * 3.14159 / 180) + 0.22;
      		glVertex2f(x, y);
   }
   glEnd();

   // Menggambar iris mata
   glColor3f(0.0, 0.0, 0.0);
   glBegin(GL_POLYGON);
   for(float i = 0; i < 360; i += 1) {
      float x = 0.075 * cos(i * 3.14159 / 180) - 0.15;
      float y = 0.075 * sin(i * 3.14159 / 180) + 0.22;
	  glVertex2f(x, y);
   }
   glEnd();
   
   glColor3f(0.0, 0.0, 0.0);
   glBegin(GL_POLYGON);
   for(float i = 0; i < 360; i += 1) {
      float x = 0.075 * cos(i * 3.14159 / 180) - 0.15 + 0.35;
      float y = 0.075 * sin(i * 3.14159 / 180) + 0.22;
	  glVertex2f(x, y);
   }
   glEnd();
   
   p += 0.55;
   }
   

   // Gambar hidung segitiga
   glColor3ub(150, 075, 0);
   glBegin(GL_TRIANGLES);
   glVertex2f(0.0, 0.05);
   glVertex2f(0.0, -0.05);
   glVertex2f(0.1, -.0);
   glEnd();
   
   // Gambar Mulut
   glColor3ub(88, 6, 1);
   glBegin(GL_POLYGON);
   for(float i = 180; i < 360; i += 1) {
      float x = 0.43 * cos(i * 3.14159 / 180);
      float y = 0.43 * sin(i * 3.14159 / 180) - 0.15;
      glVertex2f(x, y);
   }
   glEnd();
   
   
   //Menggamnbar lidah
   glColor3ub(138, 15, 16);
   glBegin(GL_POLYGON);
   for(float i = 0; i < 360; i += 1) {
      float x = 0.3 * cos(i * 3.14159 / 180);
      float y = 0.15 * sin(i * 3.14159 / 180)-0.44;
      glVertex2f(x, y);
   }
   glEnd();
   
   // Gambar garis
   glLineWidth(2.5f);
   glColor3ub(30, 33, 15);
   glBegin(GL_LINES);
   glVertex3f(0, -0.38, 0.0f);
   glVertex3f(0, -0.5, 0.0f);
   glEnd();
   
// Gambar Alis

	
	// Gambar titik
	
	glPointSize(2);
   	glBegin(GL_POINTS);
   	
	glColor3ub(255, 255, 255);
	glVertex2f(-0.3,0.24);
   
   	glEnd();
   
   //Gambar Gigi
   float h = 0;
   for(float j=0; j<2; j++){
   	glBegin(GL_TRIANGLE_FAN);
   glColor3ub(255, 255, 255);
   
   
   glVertex2f(-0.15+h,-0.15);
   glVertex2f(-0.02+h,-0.15);
   glVertex2f(-0.02+h,-0.27);
   glVertex2f(-0.15+h,-0.27);
   
   glEnd();
   
   h+= 0.17;
   }
   
   //Gambar Gigi
   float b = 0;
   for(float j=0; j<3; j++){
   	glBegin(GL_TRIANGLE_FAN);
   glColor3ub(255, 255, 255);
   
   
//   glVertex2f(-0.2+b,-0.45);
//   glVertex2f(-0.07+b,-0.45);
//   glVertex2f(-0.07+b,-0.58);
//   glVertex2f(-0.2+b,-0.58);
   
   glEnd();
   
   b+= 0.15;
   }
   
   // luka jait
   
    glLineWidth(2.0f);
	glColor3ub(30, 33, 15);
	glBegin(GL_LINES);
	glVertex3f(0.32, 0.02, 0.0f);
	glVertex3f(0.34, -0.05, 0.0f);
	
	glVertex3f(0.42, 0.05, 0.0f);
	glVertex3f(0.44, -0.01, 0.0f);
	glEnd();
   
   //kurva
   	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
    glEnable(GL_MAP1_VERTEX_3);
    glBegin(GL_LINE_STRIP);
    glColor3f(0, 0, 0); 
    
    
    //Kemudian, for loop akan dieksekusi sebanyak 101 kali untuk mengevaluasi 101 titik pada kurva Bezier, 
	//yang terdiri dari titik-titik pada parameter kurva dengan jarak antara parameter 0.0 dan 1.0 yang sama.
	
	
    for (int i = 0; i <= 100; i++) 
    glEvalCoord1f((GLfloat) i/100.0);
    glEnd();
    
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints1[0][0]);
    glEnable(GL_MAP1_VERTEX_3);
    glBegin(GL_LINE_STRIP);
    glColor3f(0, 0, 0);
	 
    for (int i = 0; i <= 100; i++) 
    glEvalCoord1f((GLfloat) i/100.0);
    glEnd();
    
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints2[0][0]);
    glEnable(GL_MAP1_VERTEX_3);
    glBegin(GL_LINE_STRIP);
    glColor3f(0, 0, 0);
	 
    for (int i = 0; i <= 100; i++) 
    glEvalCoord1f((GLfloat) i/100.0);
    glEnd();
   
   glFlush();
}

 

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("Tugas UTS Ravel Erlindo");
   glMatrixMode(GL_PROJECTION);
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}
