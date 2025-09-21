#pragma once

#include <Arduino.h>
#include <PseudoTask.h>

class CycleTask {
public:
  CycleTask(int interval);
  void start();
  void stop();
  bool isFired(void);
  bool isActive(void);
  void update(void);

private:
  uint32_t last_millis;
  uint32_t interval;
  bool active;
  bool fired;
};

class OneShotTask {
public:
  OneShotTask();
  void start(int interval);
  void stop();
  bool isFired(void);
  bool isActive(void);
  void update(void);

private:
  uint32_t time;
  bool active;
  bool fired;
};