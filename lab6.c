

#include <stdio.h>
#include <draw.h>
#include <math.h>

int main(int argc, char* argv[])
{
    int i, j;
    int x = 100;
    int y = 100;
    int  number = 10;
    int a = 0;
    int b = 0;
    int d = 0;
    int c = 0;
    printf("How many squares should display in the blue/cyan row?");
    scanf("%d", &number);

    draw_begin();                //to draw vertical grid line.
    draw_setColor("grey");
    for (c = 0; c < 40; c++)
    {
        draw_moveTo(a, b);
        draw_lineTo(a, 250);

        a = a + 10;
    }
    draw_finish();

    draw_begin();             // to draw horizontal grid line.
    draw_setColor("grey");
    a = 0;
    b = 0;
    for (d = 0; d < 40; d++)
    {

        draw_moveTo(a, b);
        draw_lineTo(380, b);
        b = b + 10;
    }
    draw_finish();
    draw_begin();         // to row row of cyan filled square.

    draw_setColor("cyan");

    for (i = 0; i < number; i++)
    {
        draw_moveTo(x, y);

        draw_lineTo(x, 110);

        x = x + 10;
        draw_lineTo(x, 110);
        draw_lineTo(x, 100);
        draw_lineTo(x, 100);



    }



    draw_finish(1);
    printf("tick\n");


    draw_begin();         // to draw row of alternating blue filled square.

    x = 100;
    for (j = 0; j < number / 2; j++)
    {
        draw_moveTo(x, 100);

        draw_lineTo(x, 110);

        x = x + 10;
        draw_lineTo(x, 110);
        draw_lineTo(x, 100);
        draw_lineTo(x, 100);
        x = x + 10;
    }


    draw_setColor("blue");

    draw_finish(1);



    draw_begin();              // to draw open black circle.
    draw_setColor("black");
    draw_arc(100, 60, 20, 0, M_PI * 2, 0);
    draw_finish(1);


    draw_begin();           // to draw open black circle.
    draw_setColor("white");
    draw_arc(100, 60, 19, 0, M_PI * 2, 0);
    draw_finish(1);

    draw_begin();
    draw_setColor("orange");      // to draw orange semi circle.
    draw_arc(130, 60, 20, 0, M_PI, 1);
    draw_finish(1);

    draw_begin();              // to draw blue semi circle.
    draw_setColor("blue");
    draw_arc(170, 60, 20, M_PI / 2, 3 * M_PI / 2, 1);
    draw_finish(1);

    draw_begin();          // to draw red open triangle.
    draw_setColor("red");
    draw_moveTo(200, 40);
    draw_lineTo(200, 80);
    draw_lineTo(240, 60);
    draw_lineTo(200, 40);
    draw_finish(1);

    draw_begin();        // to draw open red triangle.
    draw_setColor("white");
    draw_moveTo(201, 41);
    draw_lineTo(201, 79);
    draw_lineTo(239, 60);
    draw_lineTo(201, 41);
    draw_finish(1);

    draw_begin();       // to draw green square.
    draw_setColor("green");
    draw_moveTo(10, 10);
    draw_lineTo(10, 50);
    draw_lineTo(50, 50);
    draw_lineTo(50, 10);
    draw_lineTo(10, 10);
    draw_finish(1);

    draw_begin();              // to draw open blue circle for smile
    draw_setColor("blue");
    draw_arc(150, 150, 30, 0, M_PI * 2, 0);
    draw_finish(1);


    draw_begin();           // to draw open blue circle for smile.
    draw_setColor("white");
    draw_arc(150, 150, 29, 0, M_PI * 2, 0);
    draw_finish(1);

    draw_begin();             // to draw eyes of smile.
    draw_setColor("blue");
    draw_arc(140, 140, 2, 0, M_PI * 2, 0);
    draw_finish(1);

    draw_begin();           // to draw open eyes for smile.
    draw_setColor("white");
    draw_arc(140, 140, 1, 0, M_PI * 2, 0);
    draw_finish(1);

    draw_begin();             // to draw eyes of smiley face.
    draw_setColor("blue");
    draw_arc(160, 140, 2, 0, M_PI * 2, 0);
    draw_finish(1);

    draw_begin();           // to draw open eyes for smiley face.
    draw_setColor("white");
    draw_arc(160, 140, 1, 0, M_PI * 2, 0);
    draw_finish(1);

    draw_begin();
    draw_setColor("blue");      // to draw smile for  blue smiley face.
    draw_arc(150, 150, 20, 0, M_PI, 0);
    draw_finish(1);

    draw_begin();
    draw_setColor("white");      // to draw orange semi circle.
    draw_arc(150, 150, 19, 0, M_PI, 0);
    draw_finish(1);








    return 0;
}

