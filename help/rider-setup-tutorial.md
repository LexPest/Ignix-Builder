HERE'S THE MAGIC INGREDIENT

In order to tell CLion where to find the wxWidgets library, you have to open CLion Preferences, then step into Build, Execution, Deployment.

Then click on CMake. You will then be presented with some CMake settings. The one we're interested in is the Environment: section.

Click on the folder on the right side of the text entry field and it will present you with a window for adding environment variables to your CMake session.

Click the + key at the bottom.

You'll see a window for entering Names and Values.

In the left column add: CMAKE_PREFIX_PATH

And in the right column, paste in the full path to your BUILD DIRECTORY, in my case: /Users/mediacomposer/Documents/wxWidgets-Debug

Once this is done, you should be able to click the little gear icon to the left of CLion's CMake log window and clear cache and reload project. If all has gone well, the error message will have disappeared, and you can now build the minimal project by clicking the little Hammer icon at the top of your CLion screen.

It should build without errors. You can then find the executable by navigating to the "minimal" folder and then one step further into the folder named: cmake-build-debug.

Double-click the icon and the minimal project will run.