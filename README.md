# RPAFirm-BotWaiters
This is a small python project for an ‘RPA’ firm which is in the process of developing a restaurant having bot-waiters.
<br>

### Problem Description
A bot is required to <b>deliver food from a specified exit door</b> of the kitchen and proceed to the specified table. The kitchen is said to have multiple exit doors.
<br>
The restaurant has blocked areas where the bot cannot move and passages where it can move. The layout of restaurant could either be rectangular or square in shape.
<br>
Layout of the map is considered to be a matrix of cells, where <b>a cell having ‘0’ represents a passage and a cell having ‘1’ represents the blocked area</b>. The bot is said to have memorised this map in a particular format, for faster processing. 
<br>
Given a particular table location, the bot must find a path from the kitchen, use the specified exit door and proceed to the table, to serve the customer. However, the bot has a <b>constraint</b>. It can move only in either rightward or downward and only one step at a time. This means that the bot can move only to the adjacent cell either to the right or downwards, provided it is not a blocked area. First preference is given to the right direction.
<br>
The layout matrix is stored in the file called "<b>input.txt</b>".
<br>
The solution must contain code that helps the bot with forming the path, from the specific exit door of the kitchen to the mentioned table(if it exists). If multiple paths exist, any one path must be considered.

### Implementation files
1. Header file - this contains function prototypes, user defined data type definitions
2. Implementation file - this contains function definitions
3. Client file - this contains the driver function
