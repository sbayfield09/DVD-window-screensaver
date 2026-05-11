#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdio.h>

bool running;
int windowX, windowY;
SDL_Renderer *renderer;
int screenWidth, screenHeight;
SDL_DisplayMode dm;
int windowSpeed = 7;
int windowDirectionX, windowDirectionY;

int main() {

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    IMG_Init(IMG_INIT_PNG);


    SDL_GetDesktopDisplayMode(0, &dm);
    screenWidth = dm.w;
    screenHeight = dm.h;

    windowDirectionX = windowSpeed, windowDirectionY = windowSpeed;

    SDL_Window* window = SDL_CreateWindow("DVD", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 100, 100, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    SDL_Surface *texSurface = IMG_Load("./Sprites/dvdlogo.png");
    SDL_Texture *texTexture = SDL_CreateTextureFromSurface(renderer, texSurface);
    printf("IMAGE POINTER = %p", texTexture);

    running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
            }
        }
        SDL_RenderCopy(renderer, texTexture, (void *)NULL, (void*)NULL);
        SDL_RenderPresent(renderer);

        if (windowX <= 0) windowDirectionX = windowSpeed;
        else if (windowX >= screenWidth - 100) windowDirectionX = 0 - windowSpeed;
        if (windowY <= 0) windowDirectionY = windowSpeed;
        else if (windowY >= screenHeight - 100) windowDirectionY = 0 - windowSpeed;

        windowX += windowDirectionX;
        windowY += windowDirectionY;
        SDL_SetWindowPosition(window, windowX, windowY);
    }


    

}