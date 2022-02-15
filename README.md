# Temperature Controller Module

### Statement

---
We used the Concepts of embedded interfacing between the micro controller and different sensors and modules to design a system that is designed to provide a temperature controlled functionality. The system shall
provide the ability to reach a targeted temperature requested by a user interface. The
system shall provide information for the user about the system state, the current
temperature and the selected set temperature.

~~~
For Furthur details on the project, please watch the attached video with the files. 
~~~

---

## Team Members

| Name | GitHub_UserName |
| ----------- | ----------- |
| Ahmed Elnoby | ahmedalnouby132 |
| Remon Albear | remonalbear |
| Abdulla Zahran | Abdolla25 |
| Mohammed Almotasem | Almotasem100 |
| Galal Hossam El-dien | Galal-Hossam-Eldien |
| Nancy Salah | NancySalah |

---

## System operation Behavior

The System is supposed to welcome the guest at first then enter the "StandBy state" where the guest to enter the desired temperature to work within about. As the shown in the following.
</br>
After that the sytem starts operating where it works within three predetermined states.
The current state is chosen according to the surrounding conditions where the state could be:

- **Operational Mode**: Where the system is working trying to acheive the chosen temperature.
- **Normal Mode**: Where the system is at the chosen temperature so it's not working though it's continously monitoring the temperature.
- **Error Mode**: Where an error had occured and a humanly interference is required so the system automatically shutdown until being rebooted for safety.

---

![Alt](Results/Screenshot%20(10).png)

---

## System architecture

**System is consisted of the following:**

1. Atmega32 Microcontroller.
2. LM016 character LCD.
3. TC72 SPI to temperature convertor.
4. 4X3 Keypad.
5. PWM to voltage convertor module.
6. Calibration resistor.

---

## System Hierarchy

![alt](Results/Screenshot%20(9).png)

![alt](Results/Screenshot%20(8).png)

---

## Results

---

**Operational Mode:**

![alt](Results/Screenshot%20(7).png)

---
**Normal Mode:**

![alt](Results/Screenshot%20(12).png)

---

**Error Mode:**

![alt](Results/Screenshot%20(5).png)
