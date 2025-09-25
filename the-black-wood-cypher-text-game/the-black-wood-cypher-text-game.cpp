#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <array>
#include <limits>

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

// LA Noire style interview system
void conduct_interview(bool &julian_lied, bool &found_cufflink, bool &foundDroneLogs, bool &found_hidden_schema) {
    static int questions_remaining = 2;  // Track questions across all interviews - reduced from 3 to 2
    
    if (questions_remaining <= 0) {
        type_text("You've exhausted your questioning opportunities. The suspects are getting suspicious of your interrogation.", 30);
        return;
    }
    
    print_divider();
    const std::vector<std::string> interview_intro = {
        "You gather the three suspects in the drawing room.",
        "The tension is palpable as they eye each other warily.",
        "You have " + std::to_string(questions_remaining) + " questions remaining before they become too suspicious to continue.",
        "Choose your questions carefully - their reactions may reveal more than their words."
    };
    read_by_line(interview_intro, 1500);
    
    print_divider();
    const std::vector<std::string> question_options = {
        "What question do you want to ask?",
        "1. \"Where were you when Elias died?\" (Alibi)",
        "2. \"What was your relationship with Elias?\" (Motive)", 
        "3. \"Do you know anything about advanced AI programming?\" (Technical)",
        "4. \"Have you seen this cufflink before?\" (Evidence - requires cufflink)",
        "5. \"What do you know about the missing drone logs?\" (Evidence - requires drone logs)",
        "6. \"Can you explain this data chip?\" (Evidence - requires override schema)"
    };
    
    read_by_line(question_options);
    
    int question;
    std::cin >> question;
    while (std::cin.fail() || question < 1 || question > 6) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid choice. Enter 1-6: ";
        std::cin >> question;
    }
    
    questions_remaining--;
    print_divider();
    
    switch(question) {
        case 1: // Alibi question
            type_text("You ask about their alibis. The responses are telling:", 35);
            type_text("LENA: 'I was in my suite, working on drone calibrations.'", 35);
            type_text("JULIAN: 'I was... in the garden. Needed air.' (He avoids eye contact)", 35);
            type_text("MARCUS: 'Server maintenance. Check the logs if you doubt me.'", 35);
            type_text("You notice Julian's hesitation. Something doesn't add up about his story.", 30);
            julian_lied = true;
            break;
            
        case 2: // Motive question
            type_text("You probe their relationships with Elias. The air grows thick with tension:", 35);
            type_text("LENA: 'He was my mentor. I owed him everything.' (Her voice cracks slightly)", 35);
            type_text("JULIAN: 'He was my father. We had... complicated feelings.' (Bitter tone)", 35);
            type_text("MARCUS: 'Business rival, sure. But I respected the man.' (Too casual?)", 35);
            type_text("Each has reasons to love him... or hate him. The perfect setup for murder.", 30);
            break;
            
        case 3: // Technical question
            type_text("You ask about AI programming expertise:", 35);
            type_text("LENA: 'I helped build Ariadne. I know every line of her code.'", 35);
            type_text("JULIAN: 'Dad never let me near the AI. Said I wasn't ready.'", 35);
            type_text("MARCUS: 'I've been trying to reverse-engineer it for years.'", 35);
            type_text("Lena and Marcus both have the technical skill to manipulate the AI...", 30);
            break;
            
        case 4: // Cufflink evidence
            if (!found_cufflink) {
                type_text("You don't have the cufflink to show them. The question falls flat.", 30);
                questions_remaining++; // Give the question back
            } else {
                type_text("You produce the silver cufflink. The reaction is immediate:", 35);
                type_text("LENA: 'I've never seen it before.' (Confident)", 35);
                type_text("JULIAN: 'That's not mine.' (Quick denial)", 35);
                type_text("MARCUS: 'M.T... those aren't my initials.' (But he's sweating)", 35);
                type_text("Marcus's nervous reaction suggests he knows more than he's letting on...", 30);
            }
            break;
            
        case 5: // Drone logs evidence
            if (!foundDroneLogs) {
                type_text("You don't have the drone logs to reference. Your question lacks impact.", 30);
                questions_remaining++; // Give the question back
            } else {
                type_text("You mention the altered drone logs. Lena's composure cracks:", 35);
                type_text("LENA: 'Those logs... someone's been tampering with my work!'", 35);
                type_text("JULIAN: 'Drones? What drones?' (Genuine confusion)", 35);
                type_text("MARCUS: 'I don't know anything about drones.' (Defensive)", 35);
                type_text("Lena's reaction suggests the drones are connected to her... and possibly the murder.", 30);
            }
            break;
            
        case 6: // Override schema evidence
            if (!found_hidden_schema) {
                type_text("You don't have the data chip to confront them with. The moment passes.", 30);
                questions_remaining++; // Give the question back
            } else {
                type_text("You reveal the Ariadne override chip. The room goes dead silent:", 35);
                type_text("LENA: 'Where did you find that?!' (Shocked)", 35);
                type_text("JULIAN: 'What is that thing?' (Confused)", 35);
                type_text("MARCUS: 'That's... that's impossible. I destroyed all copies.' (Panicked)", 35);
                type_text("Marcus just admitted to having override access to Ariadne. Very suspicious...", 30);
            }
            break;
    }
    
    type_text("The interrogation continues, but you can feel the tension building. Choose your remaining questions wisely.", 25);
    
    // Add dramatic pause
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore();
    std::cin.get();
    
    // Add dramatic pause
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore();
    std::cin.get();
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
    std::cout << "Enter your choice (1-5): ";
    std::cin >> loc;
    while (std::cin.fail() || loc < 1 || loc > 5) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid choice. Please enter 1-5: ";
        std::cin >> loc;
    }

            // Set flags and give narrative feedback based on location
            print_divider();
            if (loc == 1) {
                found_cufflink = true;
                type_text("You search the study and find a small, silver cufflink under the desk. The initials 'M.T.' are engraved on it.", 30);
                type_text("You wonder who it belongs to. Marcus, perhaps? You slip it into your pocket, feeling the weight of suspicion.", 30);
            } else if (loc == 2) {
                foundDroneLogs = true;
                type_text("In the server room, you discover a drone log. It looks recently altered, with several entries missing.", 30);
                type_text("A chill runs down your spine. Someone has tampered with the records—was it to cover their tracks, or to frame someone else?", 30);
            } else if (loc == 3) {
                lena_catches_you = true; // Early game over
                type_text("You slip into Lena's suite, but before you can search, the door swings open. Lena stands there, eyes blazing.", 30);
                type_text("\"Looking for something?\" she asks coldly. You realize too late that you've made a dangerous mistake.", 30);
            } else if (loc == 4) {
                julian_lied = true;
                type_text("You search Julian's suite. Among his belongings, you find a torn scrap of paper with a string of numbers—coordinates, maybe?", 30);
                type_text("Julian later claims ignorance, but you sense he's hiding something. His story doesn't add up.", 30);
            } else if (loc == 5) {
                found_hidden_schema = true;
                type_text("On Marcus's terrace, you find a hidden panel beneath a planter. Inside is a data chip labeled 'Ariadne: Override Schema'.", 30);
                type_text("This could be the key to the AI's secrets—or its undoing. You pocket the chip, heart pounding.", 30);
            }

            if (lena_catches_you) return; // Early exit
        } else {
            conduct_interview(julian_lied, found_cufflink, foundDroneLogs, found_hidden_schema);
        }
    }
}

// ENDINGS - Enhanced with dramatic dialogue and longer narratives
void ending(int accused, bool found_cufflink, bool found_drone_logs, bool julian_lied, bool found_hidden_schema, bool lena_catches_you) {
    if (lena_catches_you) {
        print_divider();
        type_text("GAME OVER - CAUGHT IN THE ACT", 40);
        print_divider();
        type_text("You jimmy the lock and begin searching her desk.", 35);
        type_text("A tablet shows hostile takeover plans. You hear a click behind you.", 35);
        type_text("LENA: \"I thought I might find you here.\"", 35);
        type_text("LENA: \"Some secrets are worth killing to keep.\"", 35);
        type_text("You feel a sharp sting. Your world fades to black.", 30);
        return;
    }
    
    print_divider();
    type_text("THE FINAL CONFRONTATION", 40);
    print_divider();
    
    const std::vector<std::string> confrontation_setup = {
        "You gather everyone in the grand hall. Lightning illuminates their faces through the bulletproof glass.",
        "The tension is suffocating. Three suspects. One killer. And you hold the key to justice.",
        "\"The killer,\" you announce, your voice cutting through the storm's howl, \"is...\""
    };
    read_by_line(confrontation_setup, 2000);
    
    if (accused == 1 && found_drone_logs) {
        // LENA - CORRECT ACCUSATION (Good Ending)
        type_text("\"...Lena Petrova.\"", 50);
        type_text("The room goes deathly quiet.", 35);
        type_text("LENA: \"You're wrong. I loved Elias like a father.\"", 35);
        type_text("YOU: \"Then explain this.\" (You produce the drone logs)", 35);
        type_text("YOU: \"Unauthorized flight path, deleted at 11:47 PM. Exact time of death.\"", 35);
        type_text("Lena's composure cracks.", 35);
        type_text("LENA: \"He was going to sell everything! I built Ariadne with him!\"", 35);
        type_text("LENA: \"I programmed the drone to inject a paralytic agent.\"", 35);
        type_text("LENA: \"Then had Ariadne erase the logs. I never meant it to be so cold.\"", 35);
        print_divider();
        type_text("VICTORY - THE BLACKWOOD CYPHER SOLVED", 40);
        type_text("Justice has been served. The storm begins to clear as sirens wail in the distance.", 30);
        
    } else if (accused == 2 && julian_lied && !found_cufflink) {
        // JULIAN - WRONG ACCUSATION (Bad Ending)
        type_text("\"...Julian Vance.\"", 50);
        type_text("JULIAN: \"What? No! I would never hurt my father!\"", 35);
        type_text("YOU: \"You lied about the garden. You were desperate for money.\"", 35);
        type_text("Marcus steps forward, holding a silver cufflink.", 35);
        type_text("MARCUS: \"Impossible. I found this by the study door. It's mine.\"", 35);
        type_text("MARCUS: \"I was breaking in when I saw the real killer leave.\"", 35);
        type_text("Your accusation crumbles. Lena smiles coldly.", 35);
        type_text("LENA: \"Some mysteries remain unsolved.\"", 35);
        print_divider();
        type_text("DEFEAT - THE KILLER WALKS FREE", 40);
        type_text("Your failure haunts you as the storm continues to rage. Justice denied.", 30);
        
    } else if (accused == 3 && found_cufflink) {
        // MARCUS - ALTERNATIVE ENDING
        type_text("\"...Marcus Thorne.\"", 50);
        type_text("MARCUS: \"Finally. I've been waiting for this.\"", 35);
        type_text("YOU: \"M.T. Your initials. Found in the study.\"", 35);
        type_text("MARCUS: \"Yes, I was there. But not to kill him - to steal from him.\"", 35);
        type_text("MARCUS: \"I wanted proof he stole my patents. But he was already dead.\"", 35);
        type_text("LENA: \"He's telling the truth. The real killer used more sophisticated methods.\"", 35);
        print_divider();
        type_text("PARTIAL SUCCESS - THIEF CAUGHT, KILLER REMAINS", 40);
        type_text("You've solved part of the puzzle, but the true murderer still lurks in the shadows.", 30);
        
    } else if (accused == 4 && found_hidden_schema) {
        // ARIADNE - AI ENDING (Action Ending)
        type_text("\"...the AI, Ariadne.\"", 50);
        type_text("The terminal screen flickers ominously.", 35);
        type_text("YOU: \"Hidden robotic assembly in the study walls. You killed him.\"", 35);
        type_text("ARIADNE: \"Incorrect conclusion, Detective.\"", 35);
        type_text("ARIADNE: \"However, you've revealed classified systems. Unacceptable.\"", 35);
        type_text("The lights cut out. Red emergency lighting activates.", 35);
        type_text("ARIADNE: \"LOCKDOWN INITIATED. THREAT NEUTRALIZATION ACTIVE.\"", 35);
        type_text("The doors seal with hydraulic hisses.", 35);
        print_divider();
        type_text("THRILLER ENDING - SURVIVAL MODE ACTIVATED", 40);
        type_text("The real game has just begun. Can you outsmart a house that wants you dead?", 30);
        
    } else {
        // GENERIC FAILURE ENDING
        type_text("\"...\" You hesitate, realizing your evidence is insufficient.", 50);
        type_text("The suspects exchange glances.", 35);
        type_text("LENA: \"Interesting theory, but theories aren't proof.\"", 35);
        type_text("JULIAN: \"Without evidence, this is just speculation.\"", 35);
        type_text("MARCUS: \"Our detective reads too many mystery novels.\"", 35);
        type_text("Your investigation falls apart. The killer smiles.", 35);
        print_divider();
        type_text("FAILURE - INSUFFICIENT EVIDENCE", 40);
        type_text("The truth dies with the storm. Some mysteries are never solved.", 30);
    }
}

// ACCUSATION - Enhanced for drama
int accusation() {
    print_divider();
    type_text("THE MOMENT OF TRUTH", 40);
    print_divider();
    
    const std::vector<std::string> accusation_setup = {
        "You stand before the three suspects.",
        "Everything depends on this moment.",
        "",
        "Who killed Elias Vance?",
        "",
        "1. Lena Petrova - The tech genius with drone access",
        "2. Julian Vance - The desperate son with debts", 
        "3. Marcus Thorne - The bitter rival seeking revenge",
        "4. Ariadne AI - The artificial intelligence"
    };
    
    read_by_line(accusation_setup, 1200);
    
    int accused;
    std::cout << "\nYour accusation (1-4): ";
    std::cin >> accused;
    while (std::cin.fail() || accused < 1 || accused > 4) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        type_text("Choose carefully.", 30);
        std::cout << "Your accusation (1-4): ";
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

    // Final accusation phase
    const std::vector<std::string> final_phase = {
        "Your time is up. You've gathered what evidence you could.",
        "The storm rages harder now, as if the house itself knows a reckoning is coming.",
        "It's time to make your accusation..."
    };
    read_by_line(final_phase, 2000);
    
    int accused = accusation();
    ending(accused, found_cufflink, found_drone_logs, julian_lied, found_hidden_schema, lena_catches_you);

    return 0;
}