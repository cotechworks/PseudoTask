#include <PseudoTask.h>

CycleTask::CycleTask(int interval) {
  this->last_millis = 0;
  this->interval = static_cast<uint32_t>(interval);
  this->active = false;
  this->fired = false;
}

void CycleTask::start(void) { this->active = true; }

void CycleTask::stop(void) { this->active = false; }

bool CycleTask::isFired(void) { return this->fired; }

bool CycleTask::isActive(void) { return this->active; }

void CycleTask::update(void) {
  int i;

  if (this->active == false) {
    return;
  } else {
    if (millis() - this->last_millis >= this->interval) {
      this->last_millis = millis();
      this->fired = true;
    } else {
      this->fired = false;
    }
  }
}

OneShotTask::OneShotTask() {
  this->time = 0;
  this->active = false;
  this->fired = false;
}

void OneShotTask::start(int interval) {
  this->time = millis() + static_cast<uint32_t>(interval);
  this->active = true;
}

void OneShotTask::stop(void) {
  this->time = 0;
  this->active = false;
}

bool OneShotTask::isFired(void) {
  if (this->fired) {
    this->fired = false;
    return true;
  }
  return false;
}

bool OneShotTask::isActive(void) { return this->active; }

void OneShotTask::update(void) {
  if (this->active == false) {
    return;
  } else {
    if (millis() >= this->time) {
      this->time = 0;
      this->fired = true;
      this->active = false;
    } else {
      this->fired = false;
    }
  }
}