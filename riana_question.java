public static void multiples ()
    {
        //Variable Declaration Section
        int integer;
        int multiples = 0;
        //Display Welcome Message
        c.clear (); // clears the screen
        c.print ("Hey there! Here's a fun multiples problem. Type in an integer of your choice, ");
        // Input Section
        // Prompt user for an integer.
        c.println ("  click <Enter> and you'll get the multiples of your integer to its amount :D");
        c.println ();
        c.print ("Enter an integer: ");
        integer = c.readInt ();
        if (integer == 0)
        {
            c.println ();
            c.println ("There's been an error. Integer needs to have value.\n Please press any key to return to menu");
            c.getChar (); // any key returns to menu
            c.clear (); // fresh screen for method
        }
        else if (integer < 0)
        {
            c.println ();
            c.println ("There's been an error. Integer needs to be positive.\n Please press any key to return to menu");
            c.getChar (); // any key returns to menu
            c.clear (); // fresh screen for method
        }
        else
        {
            //Display multiples message of integer entered
            c.println ();
            c.print ("Multiples of " + integer + " are ");
            //Processing and Output section
            //Calculate multiples of integer in the amount of the integer
            for (int loop = 1 ; loop <= integer ; loop = loop + 1)
            {
                multiples = multiples + integer;
                c.print (multiples + " "); //Display multiples of integer
            }
            //Output section
            //Display goodbye message.
            c.println ("\n");
            c.println ("Here are the multiples of your integer's quantity! Hope to see you again!");
            c.println ("Press any key to return to menu");
            c.getChar (); // any key returns to menu
            c.clear (); // fresh screen for method
        }
    }
