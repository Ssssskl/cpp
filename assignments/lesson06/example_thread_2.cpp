#include <chrono>
#include <iostream>
#include <thread>

void foo() {
  std::cout << "Поток работает!" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "Поток завершен!" << std::endl;
}

int main() {
  std::thread t(foo);
  t.detach();  // Отделяем поток, чтобы он работал независимо

  std::cout << "Основной поток продолжает работу..." << std::endl;

  // Даем время для завершения потока
  std::this_thread::sleep_for(std::chrono::seconds(3));

  return 0;
}