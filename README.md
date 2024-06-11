# Assignment 2 Console Editor Advanced Test Plan

Start the program, append random text using command 'a'.
<img width="675" alt="image" src="https://github.com/Tabatskyi/Assignment1-Console-Editor/assets/115981919/f2242edb-d49f-4d4d-972d-71d784eba3fd">

Print result with command 'p'.                                                                        
<img width="675" alt="image" src="https://github.com/Tabatskyi/Assignment1-Console-Editor/assets/115981919/f56348a6-ab90-4a17-ab18-90515ff8012c">

Insert the random text to the start using the 'i' command and line '0' and row '0'. Print result with command 'p'.
<img width="675" alt="image" src="https://github.com/Tabatskyi/Assignment1-Console-Editor/assets/115981919/4132234d-d0a4-450b-a0c8-4b1477c2a13a">

Save result to 'MyText.txt' file using the 's' command.
<img width="675" alt="image" src="https://github.com/Tabatskyi/Assignment1-Console-Editor/assets/115981919/08ff6505-81fe-4cc8-8830-69010fa11ce5">

Open the file with Notepad.
<img width="1073" alt="image" src="https://github.com/Tabatskyi/Assignment1-Console-Editor/assets/115981919/205397c9-5136-4c7a-afb3-5ffe00b4f2b6">

Load the sherlock.txt file with command 'l'. Print result with command 'p'. The program features dynamic memory array, so we expect resizing of memory.
<img width="1244" alt="image" src="https://github.com/Tabatskyi/Assignment1-Console-Editor/assets/115981919/f5e8e6cf-ad50-4166-952d-94adef5da026">

Insert the random text to the line '1123' and random row using the 'i' command. Work as expected.
<img width="1244" alt="image" src="https://github.com/Tabatskyi/Assignment1-Console-Editor/assets/115981919/ba49ecdc-26a5-4feb-baa6-00377143ab8d">

Find the 'Holmes' across the file using 'f' command and search text after prompt. As expected, name of main character occurs many times.
<img width="1244" alt="image" src="https://github.com/Tabatskyi/Assignment1-Console-Editor/assets/115981919/031a9d0c-1b85-42c7-ba14-dcc5075427ed">

Append the random text using command 'a' and text after prompted. Text appends on the last row, as expected.
<img width="1244" alt="image" src="https://github.com/Tabatskyi/Assignment1-Console-Editor/assets/115981919/bbe9fa55-dda5-4731-b0e4-836464a2a1f1">

Start new line with 'n' command. New line started, nice.
<img width="1244" alt="image" src="https://github.com/Tabatskyi/Assignment1-Console-Editor/assets/115981919/0fe9bdf9-5fa9-4374-b0ae-7d570af1df5f">

Save file to the 'sherlock.txt' using the 's' command. File saved.
<img width="1244" alt="image" src="https://github.com/Tabatskyi/Assignment1-Console-Editor/assets/115981919/c7d03076-f491-4340-b490-3aeb94be6f22">

Program features dynamic clipboard. So we can copy, cut and paste text.
Use copy with command 'c'. And paste text to another place with 'v'
<img width="675" alt="image" src="https://github.com/Tabatskyi/Assignment2_Console_Editor_Advanced/assets/115981919/cdd8efb7-3af3-4b06-ad26-54110e7278e7">
Output
<img width="675" alt="image" src="https://github.com/Tabatskyi/Assignment2_Console_Editor_Advanced/assets/115981919/80b6a6f8-4415-4ece-9c55-58aca885eef6">

Repeat for cut command using 'x'.
<img width="675" alt="image" src="https://github.com/Tabatskyi/Assignment2_Console_Editor_Advanced/assets/115981919/8bdbd862-d617-41bf-bcbf-b97ecffe325c">
Output
<img width="675" alt="image" src="https://github.com/Tabatskyi/Assignment2_Console_Editor_Advanced/assets/115981919/7d77b4e7-ab86-4ace-a553-e5adc1ceea7c">

Also program features undo and redo commands
Lets load smaller file 'ohio.txt' and execute 'x'. After execution print result and execute undo with command 'u'
<img width="1440" alt="image" src="https://github.com/Tabatskyi/Assignment2_Console_Editor_Advanced/assets/115981919/a098c1ae-9a69-48e9-8845-36a0e584a621">
After succesful undo lets redo with 'z'
<img width="1440" alt="image" src="https://github.com/Tabatskyi/Assignment2_Console_Editor_Advanced/assets/115981919/e1532639-4451-4741-b18c-a39038de1e14">

Also additional command was added to program such as Delete 'd' and Replace 'r'
<img width="1440" alt="image" src="https://github.com/Tabatskyi/Assignment2_Console_Editor_Advanced/assets/115981919/724005ff-3950-4567-b8f3-2d39b25b80ce">

Also program features the erase command 'e' and quit 'q'.
<img width="1244" alt="image" src="https://github.com/Tabatskyi/Assignment1-Console-Editor/assets/115981919/98f5b31b-5f1a-45f5-8566-14ffd7accad0">
