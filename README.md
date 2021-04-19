# A Text Adventure Game
 
 Authors: [Benjamin Denzler](https://github.com/ben-denzler), [Ashley Pang](https://github.com/apang024), [Joshua Beed](https://github.com/jbeed33)
 
## Project Description
 
 This is a simple text-based RPG that has a story, choice of characters, inventory for armor/weapons/items, turn-based combat and several endings that depend on choices you make during the game. The game takes place in "steps" that can be narrative or combat. Dialogue choices are made while not in combat, and battles have options to attack, run etc.

 We were interested in this project because we grew up playing video games (at least to some extent) and thought that trying to make one ourselves would be a fun and exciting project. A role-playing game is fairly open-ended compared to other ideas, and so allows us to be more creative- we can write our own story! A more open-ended project like this will also help us better understand the need for design patterns to structure our program.

 ### Languages, tools and technologies being used
 * [C++](https://en.wikipedia.org/wiki/C%2B%2B) - Our choice of coding language for the project
 * [Git](https://git-scm.com/) and [GitHub](https://github.com/) - Version control and project management tools
 * [Visual Studio Code](https://code.visualstudio.com/) - Robust code editor with an integrated terminal and Git support
 * [LucidChart](https://www.lucidchart.com/) - Tool for creating OMT class diagrams

 ### Project input/output
 * **Input:** User enters numbers corresponding to choices they can make during dialogue and combat scenes. For example, when not in combat, user could choose to travel down path 1 or 2, or could access their inventory before deciding. Invalid input is ignored.
 * **Output:** The game primarily outputs sentences describing the situation to the user and prompts them to make choices until they reach the end of the game. There are no graphical elements for the environment etc., only text. Outputs are continually displayed until the user gives input.

 ### Design patterns to be used
 * **Composite:** 
    * We're using the Composite design pattern primarily for the game's inventory system. We'd like to give the character different inventories: armor, weapons and items, for example. This could be implemented by creating arrays or vectors for each one, but this method would quickly become messy. If we wanted lots of inventories and items, we'd need lots of arrays in our character class. Also, hardcoding the player's inventories as arrays prevents us from easily adding or removing inventories throughout the game. 

    * The Composite design pattern fixes these problems by allowing us to define an Inventory object as a composite that can contain items *or* other inventories. This way, we can simply give our character class a single Inventory object and add other inventories to it as needed. This approach both simplifies the structure of our character class and allows us to dynamically add and remove inventories throughout the game (if you get a new backpack, for example).

* **Factory:**
    * The Factory design pattern is being used for character and enemy creation. The player should be able to choose from a number of pre-created characters when they start the game, and enemy encounters should randomly select from one of several enemies to fight. Each character and enemy will be their own class, but we don't know which classes will be needed until runtime. Without a design pattern for this, our `main()` would need lots of branches to decide which objects to create, which is messy and hard to maintain at large scale.

    * The Factory design pattern fixes these problems by letting dedicated Factory classes handle object creation for us. We can define our classes for characters and enemies, then simply call the Factory class to make one. For the player's character, the character Factory would take user input, and for enemies, we can give it random input with `rand()` or similar. This greatly simplifies object creation and allows for much cleaner code that is easier to maintain.

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
