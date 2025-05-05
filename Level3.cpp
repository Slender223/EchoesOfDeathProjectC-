#include "Level3.h"

Level3::Level3(sf::RenderWindow& window, sf::Sprite& sprite, sf::Texture& texture, Player& playerRef) :player(playerRef) {
    if (!displayPicture("level3.png", texture, sprite)) {
        cout << "Cannot load picture!!";
        return;
    }
    if (!font.loadFromFile("PixelifySans-Regular.ttf")) {
        cout << "Error loading font!" << endl;
        return;
    }

    //autopsy
    string qText1 = "What was the primary cause of death for Aegis?";
    Questions q1(qText1, { "A precise stab wound to the chest", "Exposure to a potent neurotoxin", "Multiple gunshot wounds", "A combination of neurotoxin and blunt force trauma" }, 3, true);
    questions.push_back(q1);

    string qText2 = "What was the primary cause of death for Titania?";
    Questions q2(qText2, { "A suppressed gunshot wound to the head", "A single, precise stab wound", "Overexposure to an unknown neurotoxin", "Suffocation" }, 2, true);
    questions.push_back(q2);

    string qText3 = "What crucial piece of evidence suggests both victims were \nincapacitated before their fatal injuries?";
    Questions q3(qText3, { "The presence of defensive wounds on both bodies", "The lack of signs of a violent struggle and the \npresence of a neurotoxin", "\nThe loud nature of the weapons used", "The significant damage to the residence indicating a prolonged figh" }, 2, true);
    questions.push_back(q3);

    string qText4 = "What type of weapon was used to inflict the fatal \nwound on Titania?";
    Questions q4(qText4, { "A large, serrated knife", "A thin, specialized knife", "A standard firearm", "An improvised weapon found at the scene" }, 2, true);
    questions.push_back(q4);

    string qText5 = "What does the autopsy report suggest about the \nindividuals who carried out the attack?";
    Questions q5(qText5, { "They were likely amateurs with little training", "They were highly trained professionals specializing in covert operations", "They engaged in a loud and chaotic confrontation with the victims", "They left significant evidence of forced entry and struggle" }, 2, true);
    questions.push_back(q5);

    string qText6 = "What was the likely method of neurotoxin \ndelivery to the victims?";
    Questions q6(qText6, { "Ingested through food or drink", " Injected directly into their bloodstream", "Released into the environment, causing inhalation", "Applied topically to their skin" }, 3, true);
    questions.push_back(q6);

    string qText7 = "Why were the victims likely unable to \neffectively defend themselves?";
    Questions q7(qText7, { "They were both asleep at the time of the attack", "The neurotoxin caused disorientation and muscle weakness", "They were outnumbered by a large group of attackers", " They were not armed at the time of the attack" }, 2, true);
    questions.push_back(q7);

    string qText8 = "What does Aegis's attempt to retrieve a firearm suggest?";
    Questions q8(qText8, { "He was the primary aggressor in a domestic dispute", " He was aware of a threat but was incapacitated\n before he could react", "\nHe was planning an attack on someone else", "He accidentally shot himself while cleaning the weapon" }, 2, true);
    questions.push_back(q8);

    string qText9 = "What does the lack of forced entry suggest about the attackers?";
    Questions q9(qText9, { "They were extremely clumsy and failed to break in properly.", "They likely had a key, were invited in, or used specialized\n methods to bypass security", "\nThey attacked through an easily accessible window", "\nThe report is incorrect, and there were signs of forced entry that were missed" }, 2, true);
    questions.push_back(q9);

    string qText10 = "The estimated time of death for both victims is very close.\n What does this suggest about the timing of the attacks?";
    Questions q10(qText10, { "Aegis was killed much earlier than Titania", "Titania died accidentally while Aegis was being attacked", "The attackers likely neutralized both victims\n within a very short timeframe", "\nThe time of death estimates are unreliable" }, 3, true);
    questions.push_back(q10);

    string qText11 = "The newspaper article details the death of Viktor Markov \nduring an operation codenamed";
    Questions q11(qText11, { "Silent Strike", "Phantom Reckoning", "Covert Elimination", "Shadow Fall" }, 2, true);
    questions.push_back(q11);

    string qText12 = "According to the article, what was Viktor Markov's primary occupation?";
    Questions q12(qText12, { "A renowned philanthropist", "The CEO of a major technology corporation", "A notorious arms dealer", "A high-ranking government official" }, 3, true);
    questions.push_back(q12);

    string qText13 = "The operation against Viktor Markov was carried out by";
    Questions q13(qText13, { "Local law enforcement", "A rival criminal organization", "A team of elite operatives", "The United Nations peacekeeping forces" }, 3, true);
    questions.push_back(q13);

    string qText14 = "The article mentions a key figure who is now seeking revenge for Viktor Markov's death. Who is it?";
    Questions q14(qText14, { "His long-time business partner", "His estranged wife", "His son, Elias Markov", "The leader of a rival syndicate" }, 3, true);
    questions.push_back(q14);

    string qText15 = "The operatives involved in the mission against Viktor Markov included individuals\n with codenames. Which of the following was \nNOT mentioned as one of those codenames?";
    Questions q15(qText15, { " Ravage", "Abyss", "Spectre", " Havoc" }, 3, true);
    questions.push_back(q15);
    
    string qText16 = "The article suggests that the intelligence provided for the \noperation against Markov was";
    Questions q16(qText16, { "Perfectly accurate, leading to a swift success", "Flawed, leading the operatives into an ambush", "Provided by Markov himself as a trap", " Withheld at the last minute" }, 2, true);
    questions.push_back(q16);

    string qText17 = "Elias Markov is described as";
    Questions q17(qText17, { "A powerful and well-known figure in the criminal underworld", "Quiet and reserved, but now potentially dangerous\n and seeking revenge", "\nHaving actively participated in his father's arms dealing business for years", "Having publicly denounced his father's criminal activities" }, 2, true);
    questions.push_back(q17);

    string qText18 = "The deaths of Aegis and Titania occurred on March 25, 2025. \nViktor Markov's death is reported on March 28, 2025. \nCould there be a connection between these events?";
    Questions q18(qText18, { "It is highly unlikely, as they occurred in different parts of the world", "It is possible, especially if Aegis and Titania were\n involved in the operation against Markov or had\n ties to his organization", "\nThe timeline suggests Aegis and Titania's deaths \nwere a direct result of Markov's death", "\nThe dates are too far apart to suggest any connection" }, 2, true);
    questions.push_back(q18);

    string qText19 = "If Aegis and Titania were highly trained individuals (as suggested by the autopsy),\n could they have been involved in the Phantom Reckoning operation?";
    Questions q19(qText19, { "\nNo, the article clearly states the operatives' codenames were different", " \nPossibly, as their occupations were unknown, \nand elite operatives often work in secrecy", "\nUnlikely, as the article implies the operation was a \nfailure for the operatives involved", "\nOnly if they were double agents working for Viktor Markov" }, 2, true);
    questions.push_back(q19);

    string qText20 = "If Elias Markov believes someone is responsible for his father's death,\n and Aegis and Titania were potentially involved in \nthe operation, what might Elias's next actions be?";
    Questions q20(qText20, { "\nTo publicly forgive those involved and move on", "To cooperate with law enforcement to bring the perpetrators \nto justice", "\nTo seek revenge against those he believes are responsible, \npotentially including Aegis and Titania if he identified them as part of the team", "\nTo disband his father's organization and live a peaceful life" }, 3, true);
    questions.push_back(q20);

    string qText21 = "According to the initial police assessment in the newspaper \narticle about the Marong killing, what was the suspected \nmotive?";
    Questions q21(qText21, { "Robbery with forced entry", "A targeted assassination", "A domestic dispute that turned violent", "A random act of violence." }, 1, true);
    questions.push_back(q21);

    string qText22 = "What detail from the Marong resident's statement \ncontradicts the initial police assessment of a break-in?";
    Questions q22(qText22, { "The victim lived on the sixth floor", "Nothing was reported stolen from the apartment", "The security in the apartment building was lax", "The victim was known to have enemies" }, 2, true);
    questions.push_back(q22);


    string qText23 = "The Marong residents compared the killing to which other \ncase, highlighting similarities in the method?";
    Questions q23(qText23, { "A recent robbery in the neighborhood", "The Allan May case", " A series of unsolved missing person cases", "A previous incident of a break-in on the sixth floor" }, 2, true);
    questions.push_back(q23);

    string qText24 = "What specific detail about the stab wounds in the \nAllan May-like case was mentioned by the second citizen\n in the newspaper article?";
    Questions q24(qText24, { " Wounds to the back", "Multiple superficial cuts", "Stab wounds to the upper chest striking \ncritical organs (lungs and heart)", "\nA single, deep stab wound to the abdomen" }, 3, true);
    questions.push_back(q24);

    string qText25 = "According to the Police Commissioner, what evidence \nsuggests the Marong killing and similar cases might be the work of \na single individual?";
    Questions q25(qText25, { " Witnesses who saw the same suspect", "The victims all knew each other", " The victims were killed by the exact same weapon", "DNA evidence found at all crime scenes" }, 3, true);
    questions.push_back(q25);

    string qText26 = "What characteristic of the killings led the Police\n Commissioner to believe the perpetrator might be a \ntrained-killer?";
    Questions q26(qText26, { "The high number of victims", "The international scope of the crimes", " The swiftness and precision of the attacks,\nwith victims killed at most on the third stab", "\nThe use of sophisticated technology to commit the crimes" }, 3, true);
    questions.push_back(q26);

    string qText27 = "According to the Autopsy Report, where were Titania\n and Aegis found?";
    Questions q27(qText27, { " In their bedroom, showing signs of struggle", "In their living room, seated comfortably in chairs", "In the kitchen, with evidence of a meal being prepared", "Outside the house, near the front entrance" }, 2, true);
    questions.push_back(q27);

    string qText28 = "What was a notable finding regarding forced entry at\n Titania and Aegis's residence?";
    Questions q28(qText28, { "The front door was visibly damaged", "A window was found broken in the back of the house", "There were no signs of forced entry through any doors or windows", " The security system was blaring when the bodies were discovered" }, 3, true);
    questions.push_back(q28);

    string qText29 = "What was the primary cause of death for both Titania and Aegis, as determined by the autopsy?";
    Questions q29(qText29, { "Blunt force trauma to the head", "Poisoning", "Multiple sharp force injuries and acute blood loss", "Strangulation" }, 3, true);
    questions.push_back(q29);

    string qText30 = "What specific type of sharp force injury was noted for \nboth Titania and Aegis in the upper chest?";
    Questions q30(qText30, { "\nSuperficial scratches", "Deep lacerations", "Two precise stab wounds that penetrated vital organs\n (lungs and heart)", "\nJagged tears consistent with a struggle" }, 3, true);
    questions.push_back(q30);

    string qText31 = "What additional precise injury contributed to the rapid blood loss in Titania?";
    Questions q31(qText31, { "A cut to the arm", "A laceration to the carotid artery", "A stab wound to the leg", "A puncture wound to the abdomen" }, 1, true);
    questions.push_back(q31);

    string qText32 = "t additional precise injury contributed to the significant blood loss in Aegis?";
    Questions q32(qText32, { "A cut to the hand", "A laceration to the jugular vein", " A stab wound to the shoulder", "A puncture wound to the neck" }, 3, true);
    questions.push_back(q32);

    string qText33 = "What significant detail from the Autopsy Report echoes the \ndescription of the Marong killing in the newspaper article?";
    Questions q33(qText33, { " The time of death was in the early morning", "The victims were found in a state of disarray", "The precise stab wounds to the upper chest striking critical organs", "Evidence of a struggle was present" }, 3, true);
    questions.push_back(q33);

    string qText34 = "Considering both the newspaper article and the Autopsy Report, \nwhat suggests a high level of skill and planning\n in Titania and Aegis's deaths?";
    Questions q34(qText34, { "\nThe presence of multiple weapons at the scene", "The loud alarm system that was triggered", "The lack of forced entry, no signs of struggle,\n and precise, fatal wounds", "The extensive damage to the property" }, 3, true);
    questions.push_back(q34);

    string qText35 = "Based on the information provided, what is a likely conclusion about \nthe connection between the Marong killing and the deaths\n of Titania and Aegis?";
    Questions q35(qText35, { "\nThey are likely unrelated incidents with different perpetrators", "They might be connected, potentially committed by the same\n skilled assassin due to the similar method of killing\n and lack of forced entry", "\nTitania and Aegis were likely victims of a robbery gone wrong, unrelated to the Marong case", "The Marong killing was a domestic dispute, while Titania and Aegis were victims of a home invasion" }, 2, true);
    questions.push_back(q35);

    string qText36 = "According to the new autopsy report, what was the \nprimary cause of death for both Spectre and Sentinel?";
    Questions q36(qText36, { "Gunshot wounds", "Poisoning by an unknown substance", "Multiple sharp force injuries and acute blood loss", " Blunt force trauma to the head" }, 3, true);
    questions.push_back(q36);

    string qText37 = "What key detail in the autopsy report suggests that \nSpectre and Sentinel were likely caught off guard and \ndid not struggle?";
    Questions q37(qText37, { "The presence of numerous defensive wounds on both bodies", "The significant disarray and signs of a violent altercation\n in the living room", "\nThe absence of defensive wounds and the undisturbed\n state of the residence.\n", "The fact that they were found in different rooms of the house" }, 3, true);
    questions.push_back(q37);

    string qText38 = "The autopsy report indicates that the sharp force injuries\n were inflicted with:\n";
    Questions q38(qText38, { "A large, blunt object", "A thin, serrated blade", "High precision, likely from a sharp, single-edged weapon", "A broken piece of household furniture" }, 3, true);
    questions.push_back(q38);

    string qText39 = "What does the lack of forced entry and the \ndeactivated/bypassed security system suggest about\n the attacker(s)?";
    Questions q39(qText39, { "They were likely inexperienced and forgot to lock up", "They were probably known to the victims or had a sophisticated\n way to enter without force\n", "\nThey must have entered through an unlocked window that wasn't\n checked\n", "\nThe security system was faulty and malfunctioned" }, 2, true);
    questions.push_back(q39);

    string qText40 = "The newspaper article details the death of Agent Caroline \nVasquez (Orca) on March 28, 2025. Spectre and Sentinel\n died on April 22, 2025. Is there any immediate \nindication that these events are connected?";
    Questions q40(qText40, { "\nYes, the dates are very close, suggesting a direct link", "Not based on the information provided so far; the \ncircumstances and timing seem different\n", "\nAbsolutely, both reports mention elite operatives", "\nOnly if Agent Vasquez knew Spectre and Sentinel personally" }, 2, true);
    questions.push_back(q40);

    string qText41 = "Agent Vasquez was part of a team targeting the Black Ember\n Syndicate. Could Spectre and Sentinel have had any connection to\n this syndicate or the intelligence community?";
    Questions q41(qText41, { "It's impossible to tell with the current information", "Their seemingly professional and silent execution could \nsuggest involvement in such circles", "The autopsy report explicitly states they had no known affiliations", " The fact that they lived in a suburban neighborhood rules out any\n such connection" }, 2, true);
    questions.push_back(q41);;

    string qText42 = "Agent Vasquez was reportedly betrayed, leading to her death. \nCould Spectre and Sentinel have been victims of a similar betrayal?";
    Questions q42(qText42, { "The lack of struggle suggests they trusted their attacker, which could imply betrayal", "The autopsy clearly states they were killed by a stranger", "Betrayal is only possible within criminal organizations", " There is no information in the autopsy report to suggest betrayal" }, 1, true);
    questions.push_back(q42);

    string qText43 = "The Black Ember Syndicate has ruthless enforcers like Ember Viper. \nCould the precise and silent nature of Spectre and Sentinel's \ndeaths be attributed to someone with similar skills?";
    Questions q43(qText43, { "No, because the weapon used was a knife, not a firearm", "Possibly, as the efficiency and lack of struggle point to a \nhighly skilled and potentially ruthless individual", "\nOnly if Ember Viper personally knew Spectre and Sentine", "\nThe autopsy report indicates the killer was likely an amateur" }, 2, true);
    questions.push_back(q43);

    string qText44 = "Consider the previous case of Aegis and Titania, who were also killed\n in a seemingly professional manner. Could there be a link between their deaths \nand the deaths of Spectre and Sentinel, or the events\n surrounding Agent Vasquez and Viktor Markov?";
    Questions q44(qText44, { "It's too early to draw any connections; these appear\n to be isolated incidents", "\nThe recurring theme of highly skilled attackers and potential\n involvement in clandestine activities warrants further investigation \ninto potential links", "The different causes of death (gunshots vs. stab wounds) rule\n out any connection", "\n All these deaths are likely random acts of violence in the criminal underworld" }, 2, true);
    questions.push_back(q44);

    string qText45 = "If Spectre and Sentinel were indeed involved in covert operations, \nwhat might be a motive for their seemingly targeted and efficient execution?";
    Questions q45(qText45, { "A random robbery gone wrong", "A personal dispute with a neighbor", "Retaliation from a criminal organization they were \ninvestigating or had crossed, or a consequence of a compromised operation", "\n A tragic accident" }, 3, true);
    questions.push_back(q45);

    string qText46 = "The newspaper article mentions a classified operation linked to the deaths\n of two former operatives, Aegis and Titania. What was the \nalleged focus of Aegis and Titania's investigation \nbefore they were declared rogue?";
    Questions q46(qText46, { "Illegal arms trafficking", "A conspiracy within the highest levels of government", "A covert project known as 'Project Revenant'– \nan alleged sleeper agent program", "\nThe disappearance of the four elite agents: Wren, Pierce, Hayes, and Monroe" }, 3, true);
    questions.push_back(q46);

    string qText47 = "According to the autopsy report, what was the cause of death\n for the individual codenamed Atlas?";
    Questions q47(qText47, { "\nAsphyxiation due to suffocation", "A fatal car explosion", "A single gunshot wound to the base of the skull", "A structural collapse in an abandoned industrial complex" }, 3, true);
    questions.push_back(q47);

    string qText48 = "The autopsy report indicates that Sable was likely incapacitated \nbefore her death. What evidence supports this conclusion?";
    Questions q48(qText48, { "The presence of a gunshot wound", "The discovery of her body in a ransacked apartment", "The detection of a sedative and paralytic agent in her lungs", "Eyewitness reports of unidentified figures near her location" }, 3, true);
    questions.push_back(q48);

    string qText49 = "The newspaper article describes the death of Dominic Hayes (Rook) \nas officially a tragic accident due to a structural collapse. \nHowever, anonymous sources suggest a different cause. \nWhat was the suspected cause of Hayes' \ndeath according to these sources?";
    Questions q49(qText49, { "\nSuicide by gunshot", "A fiery car explosion", "Drowning in a secure location", "Execution by multiple gunshots" }, 4, true);
    questions.push_back(q49);

    string qText50 = "Both the newspaper article and the autopsy report describe deaths\n occurring under suspicious circumstances. Which of the following \ndetails from the autopsy report echoes the suspicious nature of \nElara Monroe's (Scry) death as described in the newspaper?";
    Questions q50(qText50, { "The presence of bruising around the neck of Atlas", "The lack of struggle and the precise nature of the gunshot wound to Atlas", "The gradual nature of Sable's asphyxiation", "The use of a plastic bag in Sable's death" }, 2, true);
    questions.push_back(q50);

    string qText51 = "The newspaper article mentions that the four deceased agents \n(Wren, Pierce, Hayes, Monroe) were all part of a classified operation. \nThe autopsy report details the deaths of Atlas and Sable. \nWhat potential connection could link these two sets of individuals?";
    Questions q51(qText51, { "\nThey were all known to have visited the same \nabandoned industrial complex", "\nThe methods of death in the autopsy report might align \nwith the suspicious circumstances surrounding the agents' deaths", "\nBoth groups were publicly acknowledged by the intelligence agency", "They all disappeared without a trace from their safe houses" }, 2, true);
    questions.push_back(q51);

    string qText52 = "Considering the details in both documents, \nwhat might be a shared motive behind the deaths of the four agents and Atlas and Sable?";
    Questions q52(qText52, { " A random series of unrelated incidents", "An internal power struggle within the intelligence agency", "The elimination of individuals who possessed knowledge of a sensitive or dangerous secret", "A foreign intelligence operation targeting specific individuals" }, 3, true);
    questions.push_back(q52);

    string qText53 = "The newspaper article highlights the agency's denial of any knowledge of the four deceased agents. \nHow does the autopsy report potentially support the idea of a clandestine operation or \nthe erasure of individuals?";
    Questions q53(qText53, { "By providing detailed personal information about Atlas and Sable", "By being conducted at a Syndicate Medical Facility – Confidential, suggesting secrecy.", "By clearly stating the official affiliations of Atlas and Sable", "By having a readily available public record" }, 2, true);
    questions.push_back(q53);

    string qText54 = "If Atlas and Sable were indeed Aegis and Titania, \nwhat could the methods of their deaths(Aegis and Titania) - \ngunshot to the head, suffocation with sedation , suggest about the nature of \nthose who ordered their elimination?";
    Questions q54(qText54, { "\nA desire for quick and painless deaths", "A highly professional and ruthless approach, utilizing \nspecific methods to ensure silence", "\nA lack of planning and reliance on improvised methods", "\nAn attempt to make the deaths appear accidenta" }, 2, true);
    questions.push_back(q54);

    string qText55 = " What was the stated cause of death for the individual known as Aegis, \naccording to the autopsy report?";
    Questions q55(qText55, { "Stab wound to the abdomen", "  Blunt force trauma to the head ", " Gunshot wounds to the torso, excessive blood loss", " Poisoning" }, 3, true);
    questions.push_back(q55);

    string qText56 = " The autopsy report for Titania mentions a specific type of wound that \nultimately caused her death. What was it?";
    Questions q56(qText56, { " Multiple gunshot wounds", " Severe blunt force trauma to the head", " Exsanguination due to a stab wound to the abdomen ", " Strangulation" }, 3, true);
    questions.push_back(q56);

    string qText57 = " The forensic pathologist's conclusion in the autopsy report \nsuggests a potential motive and perpetrator for Aegis and Titania's deaths. \nWho is suspected, and what is the likely motive?";
    Questions q57(qText57, { " Dr. Emil Rausch, to silence those who knew about his experiments", " A rival intelligence agency, due to Aegis and Titania's effectiveness.", " Elias Markov's network, in revenge for the death of his father, Viktor Markov. ", " The government itself, to cover up the truth about Rausch" }, 3, true);
    questions.push_back(q57);

    string qText58 = " What piece of evidence mentioned in the autopsy report strongly suggests the \ninvolvement of Elias Markov's network?";
    Questions q58(qText58, { " The type of firearms used in Aegis's death.", " The lack of defensive wounds on Titania", " A symbol etched into the floor near Titania's body", " The presence of a specific toxin in their systems" }, 3, true);
    questions.push_back(q58);

    string qText59 = " Based on the newspaper article, what were Aegis and Titania \ninitially investigating before they were declared rogue?";
    Questions q59(qText59, { " The disappearance of other intelligence operatives", " The financial backers of Dr. Emil Rausch's continued research", "  The true extent of Dr. Emil Rausch's neurological manipulation\n and human augmentation experiments", " \nCorruption within their own intelligence agency" }, 3, true);
    questions.push_back(q59);

    string qText60 = " The autopsy report for Aegis notes a \"superficial gunshot wound to the left forearm.\" \nWhat does the report suggest this type of injury\n is consistent with?";
    Questions q60(qText60, { "A shot fired by an untrained assailant "," A self-inflicted wound ", " A defensive wound sustained while attempting to block an incoming shot"," An accidental discharge of a firearm." }, 3, true);
    questions.push_back(q60);

    string qText61 = "Both autopsy reports mention \"defensive injuries\" on the bodies. \nWhat do these injuries generally indicate about \nthe circumstances of their deaths?";
    Questions q61(qText61, { "That they were killed instantly without a struggle", "That they were aware of the attack and attempted to protect themselves", "That they were incapacitated before the attack began", "That the attackers were careless and inflicted unnecessary harm" }, 2, true);
    questions.push_back(q61);

    string qText62 = "According to the newspaper article, \nwhat disturbing possibility is raised regarding Aegis and Titania's\n involvement with Dr. Rausch's work?";
    Questions q62(qText62, { " They were secretly funding his research all along ", "They were double agents working against their own agency", " They were chosen as subjects in his experiments without their knowledge ", "They were responsible for helping Rausch escape after his lab was initially raided" }, 3, true);
    questions.push_back(q62);

    string qText63 = "Titania's autopsy report mentions a \"shallow incision wound across the left forearm.\" What is this injury indicative of?";
    Questions q63(qText63, { " A deliberate act of self-harm before the attack", "A wound inflicted after she was already deceased", " A defensive wound sustained while trying to block or grab the assailant’s weapon", "An accidental cut from a sharp object in the environment" }, 3, true);
    questions.push_back(q63);

    string qText64 = "The autopsy report notes the \"lack of forced entry\" at the scene of Titania's death. What does this suggest about the perpetrators?";
    Questions q64(qText64, { "They were likely amateurs who didn't think to cover their tracks", "They probably used brute force to break down the door", "They had knowledge of the victims' security measures\n and movement patterns", "\nThey were likely known to the victims and were allowed inside" }, 3, true);
    questions.push_back(q64);


    // instructions 
    instructioDisplay.setFont(font);
    instructioDisplay.setCharacterSize(50);
    instructioDisplay.setFillColor(sf::Color::White);
    instructioDisplay.setPosition(35.0f, 100.0f);
    ifstream riddleFile("Textfiles/Level 3 instructions.txt");
    if (riddleFile.is_open()) {
        stringstream buffer;
        buffer << riddleFile.rdbuf();
        instructionText = buffer.str();
        riddleFile.close();
    }
    else {
        instructionText = "Error: Could not load riddle.";
    }
    instructioDisplay.setString(instructionText);

    hearts.clear();
    hearts.resize(player.getLives());
    int i = 0;
    for (auto itr = hearts.begin(); itr != hearts.end(); itr++, i++) {
        if (!displayPicture("heart.png", heartTexture, *itr))
            return;
        itr->setPosition(10 + i * 45, 10);
        itr->setScale(0.1f, 0.1f);
    }
    points.setString("Points: " + to_string(player.getPoints()));

    timerBox.setSize(sf::Vector2f(210.f, 75.f));
    timerBox.setFillColor(sf::Color::Black);
    timerBox.setPosition(1390.0f, 40.0f);
    time.setFont(font);
    time.setCharacterSize(35);
    time.setFillColor(sf::Color::White);
    time.setPosition(1400.0f, 45.0f);
    time.setString("Time: 15:00");

    // Adjust points box position
    pointsBox.setSize(sf::Vector2f(210.f, 75.f));
    pointsBox.setFillColor(sf::Color::Black);
    pointsBox.setPosition(700.0f, 40.0f);

    points.setFont(font);
    points.setCharacterSize(35);
    points.setFillColor(sf::Color::White);
    points.setPosition(710.0f, 45.0f);
    

    timeLimit = 900.0f; // 10 minutes in seconds
    timeRemaining = timeLimit;
    timerStarted = false;
}

int Level3::start(sf::RenderWindow& window, sf::Sprite& sprite, sf::Texture& texture) {
    points.setString("Points: " + to_string(player.getPoints()));
    bool instructionJustEnded = false;
    sf::Clock c;
    bool buttonClicked = false;
    bool inRoom = false;
    int roomNo = 0;
    bool infoPhase = false;
    bool displayNP = false;
    bool flickNP = false;
    bool quesPhase = false;
    int count = 0;
    int questionCount = 1;
    int correct = 0;
    int autoNo = 1;
    int wrongAttempts = 0;
    bool firstAttemptWrong = false;
    bool isGameOver = false;
    bool timerStarted = true;
    float timeRemaining = timeLimit;
    bool instructionTime = true;
    int correctAnswers = 0;

    sf::RectangleShape startButton(sf::Vector2f(400.0f, 180.0f));
    startButton.setFillColor(sf::Color::Black);
    startButton.setPosition(600.0f, 1000.0f);
    sf::RectangleShape proceedButton(sf::Vector2f(250.0f, 110.0f));
    proceedButton.setFillColor(sf::Color::Black);
    proceedButton.setPosition(1270.0f, 1200.0f);
    text.setCharacterSize(80);
    text.setFillColor(sf::Color::White);
    text.setPosition(670.0f, 1025.0f);
    text.setFont(font);
    sf::Texture avTexture;
    sf::Sprite avSprite;
    sf::Texture infoTexture;
    sf::Sprite infoSprite;
    sf::Texture flickerTexture;
    sf::Sprite flickerSprite;
    Avatar avatar(avTexture, avSprite);
    while (window.isOpen()) {

        sf::Event event;
        sf::Time elapsed = clickClock.getElapsedTime();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (startButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                        buttonClicked = true;
                        instructionTime = true;
                    }
                    else if (!instructioDisplay.getGlobalBounds().contains(mousePos) && instructionTime) {
                        instructionTime = false;
                        instructionJustEnded = true; // Mark that it just ended
                    }
                    if (flickerSprite.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                        infoPhase = true;

                    }

                    if (proceedButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                        if (autoNo < autoInRoom[roomNo - 1]) {
                            autoNo++;
                        }
                        else {
                            autoNo = 1;
                            displayNP = true;
                            flickNP = true;
                            infoPhase = false;
                            count++;
                            if (count % 2 == 0)
                                quesPhase = true;
                        }

                    }
                    for (int i = 0; i < questions[questionCount - 1].options.size(); i++) {
                        if (questions[questionCount - 1].optionsAsText()[i].getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                            bool isCorrect = (questions[questionCount - 1].correctAnswerIndex == i + 1);
                            questions[questionCount - 1].optionColor[i] = ((isCorrect) ? sf::Color::Green : sf::Color::Red);
                            if (!isCorrect) {
                                wrongAttempts++;
                                if (wrongAttempts >= 2) {
                                    player - 0;
                                    if (!hearts.empty()) {
                                        hearts.pop_back();
                                    }
                                    wrongAttempts = 0;
                                }
                                questions[questionCount - 1].optionColor[questions[questionCount - 1].correctAnswerIndex - 1] = sf::Color::Green;
                                player - 0;
                            }
                            else {
                                player + 5;
                                correctAnswers++;
                                correct++;
                            }
                            points.setString("Points: " + to_string(player.getPoints()));

                            drawWindow(window, { sprite }, questions[questionCount - 1]);
                            sf::sleep(sf::milliseconds(700));

                            questionCount++;

                            if (quesPhase) {
                                displayNP = false;
                                flickNP = false;
                                infoPhase = false;
                            }

                            if (correct == 5 || questionCount == quesInRoom[roomNo] - 1) {
                                inRoom = false;
                                displayNP = false;
                                flickNP = false;
                                quesPhase = false;
                                correct = 0;
                                avatar.LoadAvatar(avSprite, 'S');
                            }
                            break;
                        }
                    }
                }
            }
        }
        sf::Time timer = c.getElapsedTime();
        if (!buttonClicked) {
            text.setString("START");
            drawWindow(window, { sprite }, startButton, text);
        }
        else if (instructionTime) {
            if (!displayPicture("maze.png", texture, sprite))
                return -1;
            drawWindow(window, { sprite }, instructioDisplay);
        }

        else {
            if (inRoom) {
                string roomName = "room" + to_string(roomNo) + ".png";
                if (!displayPicture(roomName, texture, sprite)) {
                    cout << "Cannot load " + roomName + "!!" << endl;
                    return -1;
                }
                sprite.setScale(1.0f, 1.0f);

                string flickName = (flickNP ? "np" : "auto") + to_string(roomNo) + ".png";
                switch (roomNo) {
                case 1:
                    flickNP ? flickerSprite.setPosition(370, 1157) : flickerSprite.setPosition(455, 81);
                    break;
                case 2:
                    flickNP ? flickerSprite.setPosition(252, 236) : flickerSprite.setPosition(784, 687);
                    break;
                case 3:
                    flickNP ? flickerSprite.setPosition(912, 980) : flickerSprite.setPosition(146, 951);
                    break;
                case 4:
                    flickNP ? flickerSprite.setPosition(320, 978) : flickerSprite.setPosition(638, 170);
                    break;
                case 5:
                    flickNP ? flickerSprite.setPosition(682, 353) : flickerSprite.setPosition(685, 1223);
                    break;
                };

                if (hearts.empty() && !isGameOver) {
                    isGameOver = true;
                    timeRemaining = timeLimit - questionClock.getElapsedTime().asSeconds();
                    time.setString(timeConverter(timeRemaining));
                }
                if (isGameOver) {
                    displayPicture("gameover.png", texture, sprite);
                    drawGameOverWindow(window, sprite);
                    sf::sleep(sf::milliseconds(2000));
                    return -1;
                }

                if (!flickerTexture.loadFromFile("Pics/" + flickName)) {
                    cout << "Error finding flicker!!" << endl;
                    return -1;
                }

                flickerSprite.setTexture(flickerTexture, true);

                if (infoPhase) {
                    string infoPicName = (displayNP ? "newspaper" + to_string(roomNo) : "autopsy" + to_string(roomNo) + "_" + to_string(autoNo)) + ".png";
                    if (!infoTexture.loadFromFile("Pics/" + infoPicName)) {
                        cout << "Error finding newspaper!!" << endl;
                        return -1;
                    }
                    displayNP ? infoSprite.setPosition(100, 50) : infoSprite.setPosition(100, 250);
                    infoSprite.setScale(1.6, 1.6);
                    infoSprite.setTexture(infoTexture, true);
                    text.setPosition(1280, 1210);
                    text.setCharacterSize(45);
                    text.setString("Proceed");
                    drawWindow(window, { sprite, infoSprite }, proceedButton, text);
                }
                else if (quesPhase) {

                    drawWindow(window, { sprite }, questions[questionCount - 1]);
                }
                else {
                    drawWindow(window, { sprite, flickerSprite });
                    sf::sleep(sf::milliseconds(700));
                    drawWindow(window, { sprite });
                }

            }
            else {
                if (!displayPicture("maze.png", texture, sprite)) {
                    cout << "Cannot load picture!!";
                    return -1;
                }
                if (Keyboard::isKeyPressed(Keyboard::Right)) {
                    avatar.LoadAvatar(avSprite, 'D');
                }
                if (Keyboard::isKeyPressed(Keyboard::Left)) {
                    avatar.LoadAvatar(avSprite, 'A');
                }
                if (Keyboard::isKeyPressed(Keyboard::Up)) {
                    if (avSprite.getPosition().y >= 700.0f) {
                        avatar.LoadAvatar(avSprite, 'W');
                    }
                }
                if (Keyboard::isKeyPressed(Keyboard::Down)) {
                    if (avSprite.getPosition().y <= 1225.f)
                    avatar.LoadAvatar(avSprite, 'S');
                }

                drawWindow(window, { sprite , avSprite });
                if (Keyboard::isKeyPressed(Keyboard::Enter)) {
                    float x = avSprite.getPosition().x;
                    float y = avSprite.getPosition().y;
                    cout << "X: " << x << ", Y: " << y << endl;

                    if (x >= -80.0f && x <= 40.0f && y == 695.0f) {
                        inRoom = true;
                        roomNo = 1;
                        questionCount = quesInRoom[roomNo - 1];
                    }
                    else if (x >= 240 && x <= 335 && y == 695) {
                        inRoom = true;
                        roomNo = 2;
                        questionCount = quesInRoom[roomNo - 1];
                    }
                    else if (x >= 570 && x <= 665 && y == 695) {
                        inRoom = true;
                        roomNo = 3;
                        questionCount = quesInRoom[roomNo - 1];
                    }
                    else if (x >= 875 && x <= 1000 && y == 695) {
                        inRoom = true;
                        roomNo = 4;
                        questionCount = quesInRoom[roomNo - 1];
                    }
                    else if (x >= 1160 && x <= 1315 && y == 695) {
                        inRoom = true;
                        roomNo = 5;
                        questionCount = quesInRoom[roomNo - 1];
                    }
                }
                drawWindow(window, { sprite , avSprite });
            }

        }
        //
        if (instructionJustEnded) {
            questionClock.restart();
            timerStarted = true;
            instructionJustEnded = false; // Reset the flag
            timeRemaining = timeLimit;
        }

        if (!isGameOver && timerStarted) {
            timeRemaining = timeLimit - questionClock.getElapsedTime().asSeconds();

            if (timeRemaining <= 0) {
                isGameOver = true;
                timeRemaining = 0;
            }
            time.setString(timeConverter(timeRemaining));
            if (hearts.empty() && !isGameOver) {
                isGameOver = true;
                timeRemaining = timeLimit - questionClock.getElapsedTime().asSeconds();
                time.setString(timeConverter(timeRemaining));
            }
        }
        if (correctAnswers == 25) {
            if (!displayPicture("gameCompletion.png", texture, sprite)) {
                cout << "Cannot load gameCompletion picture!!";
                return -1;
            }
            drawWindow(window, sprite, text);
            sf::sleep(sf::seconds(5));
        }
    }
    return 0;
}

bool Level3::displayPicture(string picName, sf::Texture& texture, sf::Sprite& sprite) {
    if (!texture.loadFromFile("Pics/" + picName))
    {
        cerr << "Error loading " + picName + " from Pics!!" << endl;
        return false;
    }
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
    //sprite.setScale(0.8f, 0.8f);
    return true;
}
string Level3::timeConverter(float time)
{
    string t = "Time | ";
    int minutes = (int)time / 60;
    int seconds = (int)time % 60;
    t += to_string(minutes) + " : " + to_string(seconds);
    return t;
}

void Level3::drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites) {
    window.clear(sf::Color::Black);
    for (sf::Sprite sp : sprites)
        window.draw(sp);
    /*for (sf::Sprite heart : hearts)
        window.draw(heart);
    window.draw(pointsBox);
    window.draw(points);*/
    window.draw(timerBox);
    window.draw(time);
    window.display();
}

void Level3::drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites, sf::Text text) {
    window.clear(sf::Color::Black);
    for (sf::Sprite sp : sprites)
        window.draw(sp);
    window.draw(text);
    window.display();
}

void Level3::drawWindow(sf::RenderWindow& window, sf::Sprite sprite, sf::Text text) {
    window.clear(sf::Color::Black);
    window.draw(sprite);
    window.draw(text);
    window.display();
}
void Level3::drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites, sf::RectangleShape button, sf::Text text) {
    window.clear(sf::Color::Black);
    for (sf::Sprite sp : sprites)
        window.draw(sp);
    window.draw(button);
    window.draw(text);
    window.display();
}

void Level3::drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites, Questions question) {
    window.clear(sf::Color::Black);
    for (sf::Sprite sp : sprites)
        window.draw(sp);
    window.draw(question.questionAsText());
    for (sf::Text option : question.optionsAsText()) {
        window.draw(option);
    }
    for (sf::Sprite heart : hearts)
        window.draw(heart);
    window.draw(pointsBox);
    window.draw(points);
    window.draw(text);
    window.draw(timerBox);
    window.draw(time);
    window.display();
}
void Level3::drawGameOverWindow(sf::RenderWindow& window, sf::Sprite& sprite) {
    window.clear(sf::Color::Black);
    window.draw(sprite);
    window.display();
}