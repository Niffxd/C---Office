# Medical Office


Final practical work of the subject **ADS** (Algorithms and data structure) of the **National Technological University** - **Tucumán Regional Faculty** (UTN-FRT) - Argentina.

It presents the challenge of creating a system of **cancellations**, **registrations** and **modifications** (CRM) based on a medical office divided into three parts, **Administration**, **Reception** and **Consulting room**.

The objective is to be able to reinforce and apply the knowledge provided in the matter during the course.
It allows to communicate through a **terminal** in a **dynamic**, **interactive** and **detailed** way so that any user can use it, being able to **validate each possible entry** as the user navigates between the systems.

## Built with
[![Dev-C++ - 5.11 TDM-GCC Release](https://img.shields.io/badge/Dev--C%2B%2B-5.11_TDM--GCC_Release-117ACA?style=for-the-badge&logo=C%2B%2B&logoColor=%23117ACA)](https://www.bloodshed.net/)

## How to use

**Start**:
Although it is not a module, it is the direct access at the beginning of the program to the other modules. It has a main menu which allows access to them.

***

**Administration**:
It is mainly based on registration, providing access to register doctors, employees or receptionists, social works and being able to see the settlement of each previously registered doctor and who has attended at least one patient, as well as a surprise!

Its functions:

   - #### Register doctors: 👩🏻‍⚕️🧑🏻‍⚕️👨🏻‍⚕️

    • Name
    • Lastname
    • Specialty
    • Days and hours of work, (Monday to Saturday)
    • Medical Licence (will serve as user)
    • Password (to be able to access the consultation system)

   - #### Register employees (receptionists): 👩🏻‍🔬🧑🏻‍🔬👨🏻‍🔬

    • Name
    • Lastname
    • User
    • Password

   - #### Register social works: ⚕️

    • Name
    • Price

   - #### See medical settlements:

    • It allows you to see how much each doctor should be paid. 💵

   - #### Employee with the highest number of records (patient registrations):

    • There is a bonus which is earned by the employee with the most records! 🥳

   - #### Exit. ❎

    • Exit of the actual system.

***

**Reception**:
The only person authorized to use this system is the employee. It allows you to log in as long as you have previously registered.
If the employee you want to enter is not registered, it will indicate an "Employee not registered" type error.
If you do not identify yourself, the system will not allow you to carry out actions, displaying an "Employee not logged in" message.

Its functions: 

   - #### Log in: 👩🏻‍🔬🧑🏻‍🔬👨🏻‍🔬

    • User
    • Password

   - #### Register Patient: 🙍🏻‍♀️🙍🏻🙍🏻‍♂️

    • Name
    • Lastname
    • Age
    • Height
    • Weight
    • Birth's Date
    • IDN (Identification document number)
    • Home
    • City
    • Social work to be agreed with their respective prices

   - #### Register Medical Appointment: 📝

    • Preview of Doctors available according to day and time

   - #### List of Attentions: 📅

    • Appointments history

   - #### Exit. ❎

    • Exit of the actual system.

***

**Consulting room**:
The only one authorized to use this system is the Doctor. It allows the doctor to log in with his registration as long as he has previously registered.
If the license plate you want to enter is not registered, it will indicate an error of the type "License plate not registered".
If you do not identify yourself, the system will not allow you to carry out actions, displaying a "Doctor not logged in" message.

***After having entered the patient's data, their information will be displayed in a form and will allow the doctor (who has previously logged) in to enter their evolution and a date of the day of care. After this, the shift will end to be able, if possible, to attend to another patient***.

Its functions:

   - #### Log in: 👩🏻‍⚕️🧑🏻‍⚕️👨🏻‍⚕️

    • Medical License
    • Password

   - #### Call patient: 🙍🏻‍♀️🙍🏻🙍🏻‍♂️

    • Name
    • Lastname

   - #### Exit. ❎

    • Exit of the actual system.

***


*Each module generates its own database in ".dat" files to be able to obtain them later if necessary.
The data will not be saved if the current operation is not completed successfully.*

# Author and Support

At the moment it is only available in Spanish, I am working on the translation and I will update it as soon as it is ready.

[![Nicolas Sanchez](https://img.shields.io/badge/Nicolas_Sanchez-0A66C2?style=for-the-badge&logo=LinkedIn&logoColor=white)](https://www.linkedin.com/in/nirsanchez/)

Leave me a message with your feedback !

[![Nicolas Sanchez](https://img.shields.io/badge/Nicolas_Sanchez-00457C?style=for-the-badge&logo=PayPal&logoColor=white)](https://www.linkedin.com/in/nirsanchez/)

Buy me a coffee if you like it ! See ya !
