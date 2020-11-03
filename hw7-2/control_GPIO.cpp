#include<iostream>
#include<sstream>
#include<fstream>
#include<string>

#define GPIO_PATH "/sys/class/gpio"

using namespace std;

void writeGPIO(string filename, string state)
{
   fstream fs;
   string path(GPIO_PATH);
   string value("/value");
   fs.open((path + filename + value).c_str(), fstream::out);
   fs << state;
   fs.close();
}

int main(int argc, char* argv[])
{
   if (argc != 3)
   {
      cout << "Usage is: ./control_GPIO [gpio_number] [state]" << endl;
      cout << "gpio_number: GPIO number to control" << endl;
      cout << "state: hi or low" << endl;
      return 2;
   }

   cout << "Starting to interface with GPIO" << endl;

   string gpio_number(argv[1]);
   string state(argv[2]);
   ostringstream s;
   s << "/gpio" << gpio_number;
   string gpio = string(s.str());

   if(state == "hi")
   {
      writeGPIO(gpio, "1");
   }
   else if(state == "low")
   {
      writeGPIO(gpio, "0");
   }
   else
   {
      cout << "Invalid entry of state" << endl;
      return 3;
   }

   cout << "Finished" << endl;
}
