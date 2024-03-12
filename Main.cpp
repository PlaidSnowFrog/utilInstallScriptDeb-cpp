#include <iostream>

void AMDinstall();
void JDKinstall();
void GCCPPinstall();
bool Ping();

int main() {
  std::cout << "Hello, World!" << '\n';
  std::cout << "This only works on DEBIAN or on DEBIAN-BASED DISTROS" << '\n';
  std::cout << "The AMDGPU drivers, a JDK, gcc and g++ will now be installed" << '\n';

  bool WifiTest = Ping();
  if (WifiTest) {
    GCCPPinstall();
    JDKinstall();
    AMDinstall();
  } else {
    std::cout << "Connect to wifi and retry" << '\n';
  }

  return 0;
}

void AMDinstall() {
  std::cout << "Installation:   AMDGPU drivers" << '\n';

  std::string command[] = {"sudo apt update", "sudo apt upgrade", "uname -r", "sudo apt install linux-headers-$(uname -r)", "sudo apt install firmware-amd-graphics"};

  for (std::string currentCommand : command) {
    system(currentCommand.c_str());
  }
  std::cout << "The system will reboot" << '\n';
  system("sudo reboot");
}

void JDKinstall() {
  std::cout << "Installation:   JDK" << '\n';

  std::string command = "sudo apt install default-jdk";

  system(command.c_str());
  std::cout << "JDK installation complete" << '\n';
}

void GCCPPinstall() {
  std::cout << "Installation:   GCC and G++" << '\n';

  std::string command[] = {"sudo apt install gcc", "sudo apt install g++"};

  for (std::string currentCommand : command) {
    system(currentCommand.c_str());
  }
  std::cout << "GCC and G++ installation complete" << '\n';
}

bool Ping() {
  std::string command = "ping -c 3 8.8.8.8 > /dev/null"; // "-c 3" pings the website only three times and "> /dev/null" makes it not echo
  int ping = system(command.c_str());

  if (ping == 0) {
    std::cout << "Wifi is reachable, installing...\n";
    return true;
  } else {
    return false;
  }
}
