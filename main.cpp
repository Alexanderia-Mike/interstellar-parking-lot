//
//  main.cpp
//  project_3_interstellar_parking_lot
//
//  Created by 娄辰飞 on 2018/12/6.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

int main(int argc, char * argv[]) {
    srand(time(0));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("look, my beatiful car!");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0,5.0,-10.0,5.0,-5.0,5.0);
    
    glutDisplayFunc(display);
//    glutDisplayFunc(test2_display);
    glutTimerFunc(25, TimeStep, 25);
//    glutDisplayFunc(test3_display);
//    glutDisplayFunc(test5_display);
    glutReshapeFunc(reshape);
    glutMainLoop();
}










void TimeStep(int n) {
    glutTimerFunc(n, TimeStep, n);
    glutPostRedisplay();
}

void reshape (int width, int height) {
    /* define the viewport transformation */
    glViewport(0, 0, 400000.0/width, 600000.0/height);
}

void display() {
    static int timee=0;
    int number=0;
    if (timee==0){
        cout << "please input the number of slots (no less than 12):" << endl;
        cin >> number;
        if (number<12)
            number=12;
        timee++;
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Singleton_of_Interstellar::Instance(number)->vehicles_move_lovely();
    Singleton_of_Interstellar::Instance(number)->vehicle_enter();
    glutSwapBuffers();
    glFlush();
}
