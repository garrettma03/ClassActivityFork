smarthome - keeps track of weather the door is open or closed. the child process gets triggered when the door is opened and checks if the door is open. if it is it closes it

robotics - same skeleton of smarthome but goes to a imageProcessing function which does the "image processing" then return to the main function

thermostat - must compile both weather.c and thermostat.c. parent process creates child who then uses execv to execute the ./weather program that then prints out todays weather.