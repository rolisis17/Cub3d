#include <stdio.h>
#include <math.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

char map[MAP_WIDTH][MAP_HEIGHT] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

float playerX = 3.0;
float playerY = 3.0;
float playerAngle = 0.0;

void castRay(float rayAngle) {
    float rayX = playerX;
    float rayY = playerY;
    
    float rayDirX = cos(rayAngle);
    float rayDirY = sin(rayAngle);
    
    float distance = 0.0;
    int hit = 0;
    
    while (!hit) {
        rayX += rayDirX;
        rayY += rayDirY;
        
        if (rayX < 0 || rayX >= MAP_WIDTH || rayY < 0 || rayY >= MAP_HEIGHT) {
            hit = 1;
            distance = 1000.0; // A large distance to indicate no hit
        } else if (map[(int)rayX][(int)rayY] == '#') {
            hit = 1;
            distance = sqrt((rayX - playerX) * (rayX - playerX) + (rayY - playerY) * (rayY - playerY));
        }
    }
    
    // Perform rendering based on the distance
    // ...
    
}

void renderScene() {
    // Render the game scene using ray casting
    for (int x = 0; x < MAP_WIDTH; x++) {
        // Calculate the ray angle based on player's angle and field of view
        float rayAngle = playerAngle - atan2(x - MAP_WIDTH / 2, MAP_WIDTH / 2);
        
        // Normalize the angle between 0 and 2*PI
        while (rayAngle < 0) {
            rayAngle += 2 * M_PI;
        }
        while (rayAngle >= 2 * M_PI) {
            rayAngle -= 2 * M_PI;
        }
        
        // Cast the ray and render the scene
        castRay(rayAngle);
    }
}

int main() {
    // Game loop
    while (1) {
        // Update player position and angle
        // ...
        
        // Render the scene
        renderScene();
        
        // Display the rendered scene
        // ...
    }
    
    return 0;
}

// with screen
#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

char map[MAP_WIDTH][MAP_HEIGHT] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

float playerX = 3.0;
float playerY = 3.0;
float playerAngle = 0.0;

void castRay(float rayAngle, SDL_Renderer *renderer) {
    float rayX = playerX;
    float rayY = playerY;
    
    float rayDirX = cos(rayAngle);
    float rayDirY = sin(rayAngle);
    
    float distance = 0.0;
    int hit = 0;
    
    while (!hit) {
        rayX += rayDirX;
        rayY += rayDirY;
        
        if (rayX < 0 || rayX >= MAP_WIDTH || rayY < 0 || rayY >= MAP_HEIGHT) {
            hit = 1;
            distance = 1000.0; // A large distance to indicate no hit
        } else if (map[(int)rayX][(int)rayY] == '#') {
            hit = 1;
            distance = sqrt((rayX - playerX) * (rayX - playerX) + (rayY - playerY) * (rayY - playerY));
        }
    }
    
    // Perform rendering based on the distance
    // Calculate the height of the wall based on the distance
    int wallHeight = (int)(WINDOW_HEIGHT / distance);
    
    // Calculate the starting and ending vertical positions of the wall
    int wallStart = -wallHeight / 2 + WINDOW_HEIGHT / 2;
    int wallEnd = wallHeight / 2 + WINDOW_HEIGHT / 2;
    
    // Ensure the wall positions are within the screen bounds
    if (wallStart < 0) wallStart = 0;
    if (wallEnd >= WINDOW_HEIGHT) wallEnd = WINDOW_HEIGHT - 1;
    
    // Set the color of the wall
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    
    // Draw the wall segment on the screen
    SDL_RenderDrawLine(renderer, x, wallStart, x, wallEnd);
}

void renderScene(SDL_Renderer *renderer) {
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    // Render the game scene using ray casting
    for (int x = 0; x < WINDOW_WIDTH; x++) {
        // Calculate the ray angle based on player's angle and field of view
        float rayAngle = playerAngle - atan2(x - WINDOW_WIDTH / 2, WINDOW_WIDTH / 2);
        
        // Normalize the angle between 0 and 2*PI
        while (rayAngle < 0) {
            rayAngle += 2 * M_PI;
        }
        while (rayAngle >= 2 * M_PI) {
            rayAngle -= 2 * M_PI;
        }
        
        // Cast the ray and render the scene
        castRay(rayAngle, renderer);
    }
    
    // Update the screen
    SDL_RenderPresent(renderer);
}

int main() {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    
    // Create a window and renderer
    SDL_Window *window = SDL_CreateWindow("Ray Casting", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    
    // Game loop
    while (1) {
        // Handle events
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                break;
        }
        
        // Update player position and angle
        // ...
        
        // Render the scene
        renderScene(renderer);
    }
    
    // Cleanup and exit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
