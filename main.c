#include "main.h"

void updateTime(DateTime *dateTimePtr)
{
    time_t timestamp = time(NULL);
    dateTimePtr->currentSecond = timestamp % 60;
    dateTimePtr->currentMinute = (timestamp / 60) % 60;
    dateTimePtr->currentHour = (timestamp / 3600 + 3) % 24;
    dateTimePtr->totalDays = timestamp / 86400;
    dateTimePtr->currentMonth = 0;
    dateTimePtr->currentYear = 1970 + (dateTimePtr->totalDays / 365);
}

int main(void)
{
    const int screenWidth = 500;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Canli Saat");

    DateTime currentDateTime;
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        updateTime(&currentDateTime);

        char timeBuffer[32];
        sprintf(timeBuffer, "%02lli:%02lli:%02lli", 
                currentDateTime.currentHour, 
                currentDateTime.currentMinute, 
                currentDateTime.currentSecond);

        // --- çizim kismi ---
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText(timeBuffer, 115, 255, 70, BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}