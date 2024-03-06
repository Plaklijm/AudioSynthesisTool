#include <iostream>

#include "application.h"

int main() {
    auto* app = new application();
    bool isFirstFrame = true;

    while (app->getIsApplicationRunning())
    {
        if (isFirstFrame)
        {
            app->initApplication();
            isFirstFrame = false;
        }

        app->runApplication();
    }
    app->terminateApplication();

    return 0;
}
