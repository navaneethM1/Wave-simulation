//g++ -Wall 1.cpp -lglut32cu -lglu32 -lopengl32
#include<stdio.h> 
#include<glut.h> 
#include<math.h> 
  
// global declaration  
float i,j,k,l,x,y,p,xmax,t; 
int a,b,choice;
// Initialization function 
void myInit(void) 
{ 
    // Reset background color with black (since all three argument is 0.0) 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
      
      
    // Set width of point to one unit
    glPointSize(4.0); 
      
    // Set window size in X- and Y- direction 
    gluOrtho2D(-780, 780, -420, 420); 
} 

// Function to display animation 
void wave_generator (void) 
{ 
    for(j = 0; j < 10000; j += 0.03)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        x = 200*cos(j);
        y = 200*sin(j); 
        for(a = -250; a <= 400; a++)
        {
            glColor3f(1.0,1.0,1.0);
            glVertex2i(a, 0);        
        }
        for(b = -250; b <= 250; b++)
        {
            glColor3f(1.0,1.0,1.0);
            glVertex2i(0, b);
        }
        for(i = 0; i < 6.29; i += 0.001)
        {    
            glColor3f(0.0,1.0,1.0);
            glVertex2i(200*cos(i),200*sin(i));
            glColor3f(1.0,1.0,0.0);
            glVertex2i(x + 20*cos(i),y + 20*sin(i));
        }
        glColor3f(120.0,0.0,0.0);
        for(k = 0; k < 200*cos(j); k += 0.001)
            glVertex2i(k,y);
        for(k = 0; k > 200*cos(j); k -= 0.001)
            glVertex2i(k,y);
        p = 0;
        for(l = j; l > 0; l -= 0.005)
        {
            glVertex2i(p,200*sin(l));
            p += 0.2;
        }
        glEnd(); 
        glFlush();      
    } 
} 

void travelling_wave (void)
{
    for ( t = 0; t < 100000000; t += 1)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        glColor3f(120.0,20.0,30.0);
        for(int b=-550;b<=550;b++)
        {
          glColor3f(120.0,20.0,30.0);
          glPointSize(1.0);
          int x1=-700;
          int y1=b;
          glVertex2i(x1,y1);
        }
        for(int b=-550;b<=550;b++)
        {
          glColor3f(120.0,20.0,30.0);
          glPointSize(1.0);
          int x1=700;
          int y1=b;
          glVertex2i(x1,y1);
        }
        for(b = -700; b <= 700; b++)
        {
            glVertex2i(b,0);
        } 

        xmax = 0.1*t-700;
      
        for(x = -700;x<700 && x < xmax ; x+=1)
        {

            glColor3f(3.0,100.0,0.0);
            glVertex2i(x,100*sin(0.001*t-0.01*(x+700)));
        }
        glEnd();
        glFlush();
    }
}

void superposition (void)
{
    for ( t = 0; t < 100000000; t += 1)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        glColor3f(120.0,20.0,30.0);
       for(int b=-550;b<=550;b++)
        {
          glColor3f(120.0,20.0,30.0);
          glPointSize(1.0);
          int x1=-700;
          int y1=b;
          glVertex2i(x1,y1);
        }
        for(int b=-550;b<=550;b++)
        {
          glColor3f(120.0,20.0,30.0);
          glPointSize(1.0);
          int x1=700;
          int y1=b;
          glVertex2i(x1,y1);
        }
        for(b = -700; b <= 700; b++)
        {
            glVertex2i(b,0);
        } 

        xmax = 0.1*t-700;
        
        for(x = -700;x<700 && x < xmax ; x+=1)
        {

            glColor3f(3.0,100.0,0.0);
            glVertex2i(x,100*sin(0.001*t-0.01*(x+700)));
            glColor3f(1.0,1.0,1.0);
            glVertex2i(x,100*sin(0.001*t-0.01*(x+700)-3.14/2));
            glColor3d(75.0,0.0,200.0);
            glVertex2i(x,100*sin(0.001*t-0.01*(x+700))+100*sin(0.001*t-0.01*(x+700)-3.14/2));
        }
        glEnd();
        glFlush();
        }
}
  
void standing_wave (void)
{
    for ( t = 0; t < 100000000; t += 1)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        glColor3f(120.0,20.0,30.0);
        for(int b=-550;b<=550;b++)
        {
          glColor3f(120.0,20.0,30.0);
          glPointSize(1.0);
          int x1=-700;
          int y1=b;
          glVertex2i(x1,y1);
        }
        for(int b=-550;b<=550;b++)
        {
          glColor3f(120.0,20.0,30.0);
          glPointSize(1.0);
          int x1=700;
          int y1=b;
          glVertex2i(x1,y1);
        }
        for(b = -700; b <= 700; b++)
        {
            glVertex2i(b,0);
        } 

        xmax = 0.1*t-700;
      
        for(x = -700;x<700 && x < xmax ; x+=1)
        {

            glColor3f(3.0,100.0,0.0);
            glVertex2i(x,100*sin(0.001*t-0.01*(x+700)));
            glColor3f(1.0,1.0,1.0);
            glVertex2i(x,100*sin(0.001*t+0.01*(x+700)));
            glColor3d(75.0,0.0,200.0);
            glVertex2i(x,100*sin(0.001*t-0.01*(x+700))+100*sin(0.001*t+0.01*(x+700)));
        }
        glEnd();
        glFlush();
    }
}
// Driver Program 
int main (int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
      
    // Display mode which is of RGB (Red Green Blue) type 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
      
    // Declares window size 
    glutInitWindowSize(1360, 768); 
      
    // Declares window position which is (0, 0) 
    // means lower left corner will indicate position (0, 0) 
    glutInitWindowPosition(0, 0); 
  
    // Name to window 
    glutCreateWindow("Visualisation of concepts of Wave"); 
  
    // Call to myInit() 
    myInit(); 
    printf("enter the choice:\n");
    printf("1:wave generation\n2:travelling wave\n3:superposition of two waves\n4:standing wave\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: glutDisplayFunc(wave_generator);
                break;
        case 2: glutDisplayFunc(travelling_wave);
                break;
        case 3: glutDisplayFunc(superposition);
                break;
        case 4: glutDisplayFunc(standing_wave);
                break;
        default:exit(0);
    }
    glutMainLoop(); 
}