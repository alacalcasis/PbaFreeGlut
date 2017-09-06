#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>


float x; float y;
void keyboard(unsigned char key, int x, int y);
void display(void);
void drawCircle(float cx, float cy, float r, int num_segments);
void drawSquare();
void drawLine(float xo, float yo, float xd, float yd);

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutCreateWindow("GLUT Test");
  glutKeyboardFunc(&keyboard);
  x = 0.05; y = 0.05;
  
  glutDisplayFunc(&display);
  glutMainLoop();

  return EXIT_SUCCESS;
}


void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
    case '\x1B':
      exit(EXIT_SUCCESS);
      break;
  }
}

void drawCircle(float cx, float cy, float r, int numSegments)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < numSegments; ii++){
        float theta = 2.0f * 3.1415926f * float(ii) / float(numSegments); // get current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();
}

void drawSquare(){
  glBegin(GL_POLYGON);
    glVertex2f(-x, -y);
    glVertex2f( x, -y);
    glVertex2f( x,  y);
    glVertex2f(-x,  y);    
  glEnd();    
}

void drawLine(float xo, float yo, float xd, float yd){
    glPointSize(3.0);
    glBegin(GL_LINES);
      glVertex2d(xo, yo);
      glVertex2d(xd, yd);
    glEnd();
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);

  // 1.0, 0.0, 0.0 --> rojo
  // 0.0, 1.0, 0.0 --> verde
  // 1.0, 1.0, 1.0 --> gris
  glColor3f(1.0f, 1.0f, 1.0f);  

  drawSquare();
  drawCircle(0.5, 0.5, 0.05, 500);
  drawLine(0,0,0.5,0.5);
  glFlush();
}

