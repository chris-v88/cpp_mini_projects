#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <array>

// constants
const std::string asciiArt = R"(
  *   )   )          (  (             )   (  (             (        (                )           
` )  /(( /(   (    ( )\ )\   )     ( /(   )\))(   '        )\ )     )\ (          ( /(   (  (    
 ( )(_))\()) ))\   )((_|(_| /(  (  )\()) ((_)()\ ) (   (  (()/(   (((_))\ ) `  )  )\()) ))\ )(   
(_(_()|(_)\ /((_) ((_)_ _ )(_)) )\((_)\  _(())\_)())\  )\  ((_))  )\__(()/( /(/( ((_)\ /((_|()\  
|_   _| |(_|_))    | _ ) ((_)_ ((_) |(_) \ \((_)/ ((_)((_) _| |  ((/ __)(_)|(_)_\| |(_|_))  ((_) 
  | | | ' \/ -_)   | _ \ / _` / _|| / /   \ \/\/ / _ Y _ Y _` |   | (_| || | '_ \) ' \/ -_)| '_| 
  |_| |_||_\___|   |___/_\__,_\__||_\_\    \_/\_/\___|___|__,_|    \___\_, | .__/|_||_\___||_|   
                                                                       |__/|_|                   
)";

const std::vector<std::string> intro_letter = {
    "\"I am on the verge of an announcement that will reshape the digital world.",
    "Your presence is requested at Blackwood Manor.\"",
    "- Elias Vance"
};

const std::vector<std::string> info_1 = {
    "Now, you stand in the grand hall of that very manor.",
    "Rain lashes against the bulletproof glass, a tempest that has cut this hyper-modern estate from the outside world.",
    "You and three other guests—the protégé, the son, the rival—are all that remain.",
    "\nAnd Elias Vance, your old friend, the brilliant, paranoid tech mogul... is dead.",
    "\nYou found him an hour ago in his study. The door was locked from the inside.",
    "The window sealed.",
    "The only other presence in the room was a silent, glowing terminal connected to \"Ariadne,\" the master AI that runs this house.",
    "\nSomeone is a killer. And you are trapped here with them.",
    "Someone is a killer. And you are trapped here with them."
};

// QUESTIONS
const std::vector<std::string> phase_1 = {
    "You stand over the body of Elias Vance.",
    "The local network is down, and the storm is getting worse.",
    "You are on your own. Where do you begin?\n",
    "1. Examine the study for physical clues before anyone else can.",
    "2. Announce the murder to the other guests and gauge their reactions.",
    "3. Query the Ariadne AI for the official security log of the last hour.\n"
};

const std::vector<std::string> study_search_prompt = {
    "You quickly search the study before anyone else can.",
    "You notice several things out of place. Where do you want to look first?",
    "1. The desk and its drawers",
    "2. The window and sill",
    "3. The carpet near the body",
    "4. The AI terminal",
    "(You may choose one area to examine closely.)"
};


// effects
void type_text(const std::string& text, int delay_ms = 55) {
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    }
    std::cout << std::endl;
}

void read_by_line(const std::vector<std::string>& lines, int delay_ms = 2000) {
    for (const auto& line : lines) {
        std::cout << line << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    }
}

// messages
void printLogo() {
    std::cout << asciiArt << std::endl;
}

void introduction_msg() {
    type_text("The invitation was as cryptic as its sender.");
    for(const auto& line : intro_letter) {
        type_text(line);
    }   
}

// PHASES
void phase_1_msg() { 
    read_by_line(phase_1);
    int choice;
    std::cout << "What do you do? (Enter 1, 2, or 3): ";
    std::cin >> choice;
    while (std::cin.fail() || choice < 1 || choice > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid choice. Please enter 1, 2, or 3: ";
        std::cin >> choice;
    }
    switch(choice) {
        case 1:
            search_study();
            break;
        case 2:
            std::cout << "You gather the guests and announce the murder...\n";
            break;
        case 3:
            std::cout << "You query the Ariadne AI...\n";
            break;
    }
}

// Mini-investigation for searching the study (choice 1)
void search_study() {
    read_by_line(study_search_prompt, 0);
    int evidence_choice;
    std::cout << "Enter your choice (1-4): ";
    std::cin >> evidence_choice;
    while (std::cin.fail() || evidence_choice < 1 || evidence_choice > 4) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid choice. Please enter 1-4: ";
        std::cin >> evidence_choice;
    }
    switch (evidence_choice) {
        case 1:
            std::cout << "You open the desk drawers. Inside, you find a hidden compartment containing a small, silver cufflink with the initials 'M.T.'\n";
            std::cout << "(You pocket the cufflink. This could be important evidence.)\n" << std::endl;
            break;
        case 2:
            std::cout << "You inspect the window and sill. The window is sealed tight, but you notice a faint, oily residue on the sill.\n";
            std::cout << "(Strange. Could someone have used a tool or device here?)\n" << std::endl;
            break;
        case 3:
            std::cout << "You kneel by the carpet. Embedded in the fibers is a tiny, broken piece of black plastic—possibly from a drone or gadget.\n";
            std::cout << "(You take the fragment. It might match something later.)\n" << std::endl;
            break;
        case 4:
            std::cout << "You examine the AI terminal. The screen is dark, but faint fingerprints are visible on the glass.\n";
            std::cout << "(Someone accessed the terminal recently. The logs may reveal more.)\n" << std::endl;
            break;
    }
    std::cout << "You hear footsteps approaching. It's time to move on.\n" << std::endl;
}

int main() {
    printLogo();
    std::cout << "Press Enter to begin...";
    std::cin.get();
    
    std::cout << "\n- - - - - - - - - - - - - - - - - - - -\n" << std::endl;
    introduction_msg();
    std::cout << "\n- - - - - - - - - - - - - - - - - - - -\n" << std::endl;
    read_by_line(info_1);

    phase_1_msg();



    return 0;
}