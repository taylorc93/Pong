#ifndef ASSET_PATH_H
#define ASSET_PATH_H

#include <iostream>
#include <string>
#include <SDL.h>

/*
 * Get the asset path for assets located in assets/subDir
 * It's assumed the project directory is structured like:
 * bin/
 *  the executable
 * assets/
 *   All assets
 */
std::string getAssetPath(){
// We need to choose the path separator properly based on which
// platform we're running on, since Windows uses a different
// separator than most systems
#ifdef _WIN32
    const char PATH_SEP = '\\';
#else
    const char PATH_SEP = '/';
#endif
    // This will hold the base asset path: Pong/assets/
    // We give it static lifetime so that we'll only need to call
    // SDL_GetBasePath once to get the executable path
    static std::string baseRes;
    if (baseRes.empty()){
        // SDL_GetBasePath will return NULL if something went wrong
        char *basePath = SDL_GetBasePath();
        if (basePath){
            baseRes = basePath;
            SDL_free(basePath);
        } else {
            std::cerr << "Error getting asset path: " << SDL_GetError() << std::endl;
            return "";
        }

        // We replace the last bin/ with assets/ to get the the asset path
        size_t pos = baseRes.rfind("bin");
        baseRes = baseRes.substr(0, pos) + "assets" + PATH_SEP;
    }

    return baseRes;
}

#endif