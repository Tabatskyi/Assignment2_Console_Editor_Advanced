# Assignment 2 Console Editor Advanced Test Plan

Start the program, append random text using command 'a'.
<img width="675" alt="image" src="https://github.com/Tabatskyi/Assignment2_Console_Editor_Advanced/assets/115981919/811c7680-d4a8-4240-91a3-4511cd4e81cf">

Print result with command 'p'. As you can see program have cursor and all logic based on it.
<img width="675" alt="image" src="https://github.com/Tabatskyi/Assignment2_Console_Editor_Advanced/assets/115981919/a50892d4-d611-48e2-b5f9-b70ddb3ff5a2">

Insert the random text to the start using the 'i' and cursor movement with 'm'. Print result with command 'p'.
<img width="675" alt="image" src="https://github.com/Tabatskyi/Assignment2_Console_Editor_Advanced/assets/115981919/142e27a0-0c50-4630-9e78-e14465254167">

Save result to 'MyText.txt' file using the 's' command.
<img width="675" alt="image" src="https://github.com/Tabatskyi/Assignment2_Console_Editor_Advanced/assets/115981919/f53a21ff-09c4-45ea-9ee9-bb9d75ddeb15">

Open the file with Notepad.
<img width="1073" alt="image" src="https://github.com/Tabatskyi/Assignment2_Console_Editor_Advanced/assets/115981919/7db23788-6eb6-4d25-9951-0a752e2781fa">

Load the sherlock.txt file with command 'l'. Print result with command 'p'. The program features dynamic memory array, so we expect resizing of memory.    
<img width="472" alt="image" src="https://github.com/Tabatskyi/Assignment2_Console_Editor_Advanced/assets/115981919/0724a455-f15d-4ded-8847-8d8c5cc2756f">
<img width="475" alt="image" src="https://github.com/Tabatskyi/Assignment2_Console_Editor_Advanced/assets/115981919/09a69b5d-70bb-47b0-ad54-116827e1751c">

Move cursor to one line up using 'm' command and then 'w'. Insert the random text using the 'i' command.
<img width="475" alt="image" src="https://github.com/Tabatskyi/Assignment2_Console_Editor_Advanced/assets/115981919/0bd7ffa0-8167-4386-acbe-5da142cb4af1">
<img width="475" alt="image" src="https://github.com/Tabatskyi/Assignment2_Console_Editor_Advanced/assets/115981919/f8f11fd4-be05-4b12-83a3-7e8d2d4720d3">

Find the 'Holmes' across the file using 'f' command and search text after prompt. As expected, name of main character occurs many times.
<img width="1244" alt="image" src="https://github.com/Tabatskyi/Assignment1-Console-Editor/assets/115981919/031a9d0c-1b85-42c7-ba14-dcc5075427ed">

Append the random text using command 'a' and text after prompted. Text appends on the last row, and cursor moves to end.
<img width="475" alt="image" src="https://github.com/Tabatskyi/Assignment2_Console_Editor_Advanced/assets/115981919/fa313d1e-9203-4f3e-870e-1bfd310707c4">
<img width="475" alt="image" src="https://github.com/Tabatskyi/Assignment2_Console_Editor_Advanced/assets/115981919/55a9378f-e1c5-41cd-883a-3b9724c976dd">

Start new line with 'n' command. New line started, and cursor moves to the end of line.
<img width="475" alt="image" src="https://github.com/Tabatskyi/Assignment2_Console_Editor_Advanced/assets/115981919/8d493d09-8e71-447d-b47c-57384ba7971c">
<img width="475" alt="image" src="https://github.com/Tabatskyi/Assignment2_Console_Editor_Advanced/assets/115981919/ce3c899d-dc05-48bc-b2f3-c862eec13b55">

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
