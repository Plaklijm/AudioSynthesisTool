//
// Created by michi on 06/03/2024.
//

#ifndef AUDIOSYNTHESISTOOLDEV_APPLICATION_H
#define AUDIOSYNTHESISTOOLDEV_APPLICATION_H


class application {
public:
    application();

    void initApplication();
    void runApplication();
    void terminateApplication();

    int getIsApplicationRunning() { return isApplicationRunning; }
private:
    struct GLFWwindow* window;
    int isApplicationRunning;
};


#endif //AUDIOSYNTHESISTOOLDEV_APPLICATION_H
