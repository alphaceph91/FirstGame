#include "raylib.h"
#include <cstdio>

int main()
{
    //window dimensions
    int width{800};//int is type of variable 
    int height{600}; //declaring the variable hieght and assigning the data type a value of 768
    InitWindow(width, height, "First Window"); //calling width and height

    //circle coordinates
    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};
    
    //circle edges
    int l_circle_x{circle_x - circle_radius}; //left
    int r_circle_x{circle_x + circle_radius}; //right
    int u_circle_y{circle_y - circle_radius}; //upper
    int b_circle_y{circle_y + circle_radius}; //below

    //axe coordinates
    int axe_x{400};
    int axe_y{0};
    int axe_length(50);

    //axe edges
    int l_axe_x{axe_x}; //left
    int r_axe_x{axe_x + axe_length}; //right
    int u_axe_y{axe_y}; //upper
    int b_axe_y{axe_y + axe_length}; //below

    int direction{10};

    bool collision_with_axe = 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (r_axe_x >= l_circle_x) && 
                        (l_axe_x <= r_circle_x);

    SetTargetFPS(60); //sets frame per second

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (collision_with_axe)
        {
            DrawText("Game Over!", 300, 300, 50, RED);
        }
        else
        {
            //game logic start

            //update circle new edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;

            //update axe new edges
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            //update collision with axe
            collision_with_axe = 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (r_axe_x >= l_circle_x) && 
                        (l_axe_x <= r_circle_x);

        }

        //Game logic start

        DrawCircle(circle_x, circle_y, circle_radius, RED); //Draw circle logic
        DrawRectangle(axe_x, axe_y, axe_length, axe_length, BLUE); //Draw rectangle logic

        //move the axe
        axe_y += direction;
        if (axe_y > height || axe_y < 0)
        {
            direction = -direction;
        }
        

        if(IsKeyDown(KEY_D) && circle_x < width)
        {
            circle_x += 10;
        }

        if(IsKeyDown(KEY_A) && circle_x > 0)
        {
            circle_x -= 10;
        }
        //Game logic end

        EndDrawing();
    }

}