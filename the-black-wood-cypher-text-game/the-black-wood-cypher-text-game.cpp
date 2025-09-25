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
    "\nSomeone is a killer. And you are trapped here with them."
};

// effects
void print_divider() {
    std::cout << "\n- - - - - - - - - - - - - - - - - - - -\n" << std::endl;
}

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

// Mini-investigation for searching the study (choice 1)
void search_study() {
    print_divider();
    const std::vector<std::string> study_search_prompt = {
        "You quickly search the study before anyone else can.",
        "You notice several things out of place."
        "- - Where do you want to look first? - - -\n",
        "1. The desk and its drawers",
        "2. The window and sill",
        "3. The carpet near the body",
        "4. The AI terminal",
        "(You may choose one area to examine closely.)"
    };

    read_by_line(study_search_prompt);
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
            print_divider();
            type_text("You open the desk drawers. Inside, you find a hidden compartment containing a small, silver cufflink with the initials 'M.T.'", 30);
            type_text("(You pocket the cufflink. This could be important evidence.)", 30);
            break;
        case 2:
            print_divider();
            type_text("You inspect the window and sill. The window is sealed tight, but you notice a faint, oily residue on the sill.", 30);
            type_text("(Strange. Could someone have used a tool or device here?)", 30);
            break;
        case 3:
            print_divider();
            type_text("You kneel by the carpet. Embedded in the fibers is a tiny, broken piece of black plastic—possibly from a drone or gadget.", 30);
            type_text("(You take the fragment. It might match something later.)", 30);
            break;
        case 4:
            print_divider();
            type_text("You examine the AI terminal. The screen is dark, but faint fingerprints are visible on the glass.", 30);
            type_text("(Someone accessed the terminal recently. The logs may reveal more.)", 30);
            break;
    }
    std::cout << "You hear footsteps approaching!" << std::endl;
    std::cout << "It's time to move on.\n" << std::endl;
}

// PHASES 1 - Searching room
void phase_1_msg() {
    const std::vector<std::string> phase_1 = {
        "You stand over the body of Elias Vance.",
        "The local network is down, and the storm is getting worse.",
        "You are on your own.",
        "- - - Where do you begin? - - -\n",
        "1. Examine the study for physical clues before anyone else can.",
        "2. Announce the murder to the other guests and gauge their reactions.",
        "3. Query the Ariadne AI for the official security log of the last hour.\n"
    };
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
        case 2: {
            const std::vector<std::string> announce_guests = {
                "You step into the grand hall and call the other guests together.",
                "Lena's eyes narrow, Julian pales, and Marcus clenches his jaw.",
                "\"Elias Vance has been murdered,\" you announce.",
                "A tense silence follows. Each guest reacts differently—shock, denial, suspicion.",
                "You watch their faces carefully, but it's hard to read their true feelings.",
                "The storm rages outside, and you realize you are truly trapped here with a killer."
            };
            read_by_line(announce_guests);
            break;
        }
        case 3: {
            const std::vector<std::string> query_ai = {
                "You approach the Ariadne terminal, its screen glowing softly in the dim light.",
                "\"Ariadne, display the security log for the last hour,\" you command.",
                "The AI's voice is calm: \"Accessing logs...\"",
                "A list of entries appears, but several lines are corrupted or missing.",
                "\"Some data is unavailable due to a system error,\" Ariadne intones.",
                "You make a note to investigate the server room later. Someone—or something—has tampered with the records."
            };
            read_by_line(query_ai);
            break;
        }
    }
}

// PHASE 3 -- Investigate loop
void phase_2_msg(bool &found_cufflink, bool &foundDroneLogs, bool &julian_lied, bool &found_hidden_schema, bool &lena_catches_you) {
    for (int i = 0; i < 3; ++i) {
        std::cout << "You have " << (3 - i) << " actions remaining. What will you do next?\n";
        std::cout << "1. Investigate a Location." << std::endl;
        std::cout << "2. Interview a Suspect.\n" << std::endl;

        int choice;
        std::cin >> choice;
        while (std::cin.fail() || (choice != 1 && choice != 2)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice. Enter 1 or 2: ";
            std::cin >> choice;
        }

        print_divider();
        if (choice == 1) {
            const std::vector<std::string> location_options = {
                "- - - Where do you want to search? - - -\n",
                "1. Study",
                "2. Server Room",
                "3. Lena's Suite",
                "4. Julian's Suite",
                "5. Marcus's Terrace"
            };
            read_by_line(location_options);
            int loc;
            std::cin >> loc;

            // Set flags based on location
            if (loc == 1) found_cufflink = true;
            if (loc == 2) foundDroneLogs = true;
            if (loc == 3) lena_catches_you = true; // Early game over
            if (loc == 4) julian_lied = true;
            if (loc == 5) found_hidden_schema = true;

            if (lena_catches_you) return; // Early exit
        } else {
            print_divider();
            const std::vector<std::string> interview_options = {
                "Who do you want to interview?",
                "1. Lena",
                "2. Julian",
                "3. Marcus"
            };
            read_by_line(interview_options);
            int suspect;
            std::cin >> suspect;
            // Set flags based on interview
            if (suspect == 2) julian_lied = true;
        }
    }
}

// ENDINGS
void ending(int accused, bool found_cufflink, bool found_drone_logs, bool julian_lied, bool found_hidden_schema, bool lena_catches_you) {
    if (lena_catches_you) {
        std::cout << "You were caught in Lena's suite. Game over.\n";
        return;
    }
    if (accused == 1 && found_drone_logs) {
        std::cout << "You accuse Lena. She confesses. Good ending!\n";
    } else if (accused == 2 && julian_lied && !found_cufflink) {
        std::cout << "You accuse Julian, but Marcus proves you wrong. Bad ending.\n";
    } else if (accused == 4 && found_hidden_schema) {
        std::cout << "You accuse Ariadne. The AI turns hostile. Action ending!\n";
    } else {
        std::cout << "Your accusation fails. The killer gets away.\n";
    }
}

// ACCOUSING
int accusation() {
    std::cout << "Who do you accuse?\n";
    std::cout << "1. Lena\n2. Julian\n3. Marcus\n4. Ariadne\n";
    int accused;
    std::cin >> accused;
    while (std::cin.fail() || accused < 1 || accused > 4) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid choice. Enter 1-4: ";
        std::cin >> accused;
    }
    return accused;
}

// MAIN
int main() {
    printLogo();
    std::cout << "Press Enter to begin...";
    std::cin.get();
    
    print_divider();
    introduction_msg();
    print_divider();
    read_by_line(info_1);

    phase_1_msg();

    // core game
    bool found_cufflink = false;
    bool found_drone_logs = false;
    bool julian_lied = false;
    bool found_hidden_schema = false;
    bool lena_catches_you = false;

    // investigate loop
    print_divider();
    

    const std::vector<std::string> phase_2_time_announce = {
        "You have a limited amount of time before the killer realizes you're onto them.",
        "You estimate you have time for about three key actions.",
    };
    read_by_line(phase_2_time_announce, 1500);
    phase_2_msg(found_cufflink, found_drone_logs, julian_lied, found_hidden_schema, lena_catches_you);

    print_divider();
    if (lena_catches_you) {
        ending(0, found_cufflink, found_drone_logs, julian_lied, found_hidden_schema, lena_catches_you);
        return 0;
    }


    return 0;
}