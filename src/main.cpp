
#include <iostream>
#include <raylib.h>
// #include <raygui.h>

using namespace std;

Color Green = Color{38, 185, 154, 255};
Color Dark_Green = Color{20, 160, 133, 255};
Color Light_Green = Color{129, 204, 184, 255};
Color Red = Color{200, 90, 110, 255};

int player_score = 0;
int cpu_score = 0;

class Ball
{
public:
    float x, y;
    int speed_x, speed_y;
    int radius;

    void draw()
    {
        DrawCircle(x, y, radius, WHITE);
    }

    void update()
    {
        x += speed_x;
        y += speed_y;

        if (y + radius >= GetScreenHeight() || y - radius <= 0)
        {
            speed_y *= -1;
        }
        if (x + radius >= GetScreenWidth()) // CPU wins
        {
            cpu_score++;
            resetBall();
        }
        if (x - radius <= 0)
        {
            player_score++;
            resetBall();
        }
    }

    void resetBall()
    {
        x = GetScreenWidth() / 2;
        y = GetScreenHeight() / 2;

        int speed_choices[2] = {-1, 1};
        speed_x = 10 * speed_choices[GetRandomValue(0, 1)];
        speed_y = 10 * speed_choices[GetRandomValue(0, 1)];
    }
};

class Paddle
{
protected:
    void LimitMovement()
    {
        if (y <= 0)
        {
            y = 0;
        }
        if (y + height >= GetScreenHeight())
        {
            y = GetScreenHeight() - height;
        }
    }

public:
    float x, y;
    float width, height;
    int speed;
    void draw()
    {
        DrawRectangle(x, y, width, height, WHITE);
    }

    void update()
    {
        // keyboard event
        if (IsKeyDown(KEY_UP))
        {
            y = y - speed;
        }
        if (IsKeyDown(KEY_DOWN))
        {
            y = y + speed;
        }
        LimitMovement();
    }
};

class cpuPaddle : public Paddle
{
public:
    void update(int ball_y)
    {
        if (y + height / 2 > ball_y)
        {
            y = y - speed;
        }
        if (y + height / 2 <= ball_y)
        {
            y = y + speed;
        }
        LimitMovement();
    }
};

Ball ball;
Paddle player;
cpuPaddle cpu;

enum GameState
{
    Welcome,
    Playing
};

int main()
{
    const int screen_width = 1280;
    const int screen_height = 800;
    InitWindow(screen_width, screen_height, "My Pong Game !");
    SetWindowState(FLAG_FULLSCREEN_MODE);

    SetTargetFPS(60);

    ball.radius = 20;
    ball.x = screen_width / 2;
    ball.y = screen_height / 2;
    ball.speed_x = 10;
    ball.speed_y = 10;

    player.width = 25;
    player.height = 120;
    player.x = screen_width - player.width - 10;
    player.y = screen_height / 2 - player.height / 2;
    player.speed = 8;

    cpu.height = 120;
    cpu.width = 25;
    cpu.x = 10;
    cpu.y = screen_height / 2 - cpu.height / 2;
    cpu.speed = 8;

    GameState gameState = Welcome;
    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        switch (gameState)
        {
        case Welcome:
            // Draw the welcome screen
            ClearBackground(Dark_Green);
            // DrawText("Welcome to Pong!", screen_width / 2 - MeasureText("Welcome to Pong!", 40) / 2, screen_height / 4, 40, WHITE);

            // Draw start button
            // if (GuiButton(Rectangle{screen_width / 2 - 80, screen_height / 2, 160, 40}, "Start"))
            // {
            //     gameState = Playing;
            // }

            // Draw quit button
            // if (GuiButton(Rectangle{screen_width / 2 - 80, screen_height / 2 + 60, 160, 40}, "Quit"))
            // {
            //     CloseWindow();
            // }
            // break;

        case Playing:
            // Update and draw game elements
            ball.update();
            player.update();
            cpu.update(ball.y);

            // Checking for collisions
            if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height}))
            {
                ball.speed_x *= -1;
            }
            if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{cpu.x, cpu.y, cpu.width, cpu.height}))
            {
                ball.speed_x *= -1;
            }

            // Draw game elements
            ClearBackground(Dark_Green);
            DrawRectangle(screen_width / 2, 0, screen_width / 2, screen_height, Green);
            DrawCircle(screen_width / 2, screen_height / 2, 150, Light_Green);
            DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
            ball.draw();
            cpu.draw();
            player.draw();
            // Draw score labels and values
            DrawText("CPU Score:", screen_width / 8, 20, 30, WHITE);
            DrawText(TextFormat("%i", cpu_score), screen_width / 4 + 30, 20, 30, WHITE);

            DrawText("Player Score:", 3 * screen_width / 4 - 120, 20, 30, WHITE);
            DrawText(TextFormat("%i", player_score), 3 * screen_width / 4 + 110, 20, 30, WHITE);
            break;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
