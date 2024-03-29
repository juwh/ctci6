#include "assorted_methods.h"

namespace ctcilib {
    int random_int(int n) {
        std::default_random_engine generator;
        generator.seed(std::random_device()());
        std::uniform_int_distribution< int > distribution(0, n-1);
        return distribution(generator);
    }

    int random_int_in_range(int min, int max) {
        return random_int(max + 1 - min) + min;
    }

    bool random_boolean() {
        return random_int_in_range(0, 1) == 0;
    }

    bool random_boolean(int percent_true) {
        return random_int_in_range(1, 100) <= percent_true;
    }

    std::vector< std::vector<bool> > random_boolean_matrix(int m, int n, int percent_true) {
        std::vector< std::vector<bool> > matrix;
        matrix.resize(m, std::vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = random_boolean(percent_true);
            }
        }
        return matrix;
    }

    std::vector< std::vector<int> > random_matrix(int m, int n, int min, int max) {
        std::vector< std::vector<int> > matrix;
        matrix.resize(m, std::vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = random_int_in_range(min, max);
            }
        }
        return matrix;
    }

    std::vector<int> random_array(int n, int min, int max) {
        std::vector<int> array(n);
        for (int j = 0; j < n; j++) {
            array[j] = random_int_in_range(min, max);
        }
        return array;
    }

    LinkedListNode<int> random_linked_list(size_t n, int min, int max) {
        LinkedListNode<int> root(random_int_in_range(min, max), nullptr, nullptr);
        for (size_t i = 1; i < n; i++) {
            int data = random_int_in_range(min, max);
            root.push_back(data);
        }
        return root;
    }

    LinkedListNode<int> linked_list_with_value(size_t n, int value) {
        LinkedListNode<int> root = LinkedListNode<int>(value, nullptr, nullptr);
        LinkedListNode<int> prev = root;
        for (size_t i = 1; i < n; i++) {
            LinkedListNode<int> next = LinkedListNode<int>(value, nullptr, nullptr);
            prev.set_next(&next);
            prev = next;
        }
        return root;
    }

    LinkedListNode<int> create_linked_list_from_array(std::vector<int> vals) {
        LinkedListNode<int> head = LinkedListNode<int>(vals.at(0), nullptr, nullptr);
        for (size_t i = 1; i < vals.size(); i++) {
            head.push_back(vals.at(i));
        }
        return head;
    }

    std::string array_to_string(std::vector<int> array, size_t start, size_t end) {
        std::string sb{};
        for (size_t i = start; i <= end; i++) {
            int v = array[i];
            sb += std::to_string(v) + ", ";
        }
        return sb.substr(0, sb.length()-2);
    }

    std::string array_to_string(std::vector<int> array) {
        if (array.size() == 0) {
            return "";
        }
        return array_to_string(array, 0, array.size() - 1);
    }

    std::string string_array_to_string(std::vector<std::string> array) {
        std::string sb{};
        for (std::string v : array) {
            sb += v + ", ";
        }
        return sb.substr(0, sb.length()-2);
    }

    std::string to_full_binary_string(int a) {
        std::string s{};
        for (size_t i = 0; i < 32; i++) {
            int lsb = a & 1;
            s.insert(0, std::to_string(lsb));
            a = a >> 1;
        }
        return s;
    }

    std::string to_base_n_string(int a, int base) {
        std::string s{};
        while (true) {
            int lastdigit = a % base;
            s.insert(0, std::to_string(lastdigit));
            a = a / base;
            if (a == 0) {
                break;
            }
        }
        return s;
    }

    void print_matrix(std::vector< std::vector<int> > matrix) {
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] < 10 && matrix[i][j] > -10) {
                    std::cout << " ";
                }
                if (matrix[i][j] < 100 && matrix[i][j] > -100) {
                    std::cout << " ";
                }
                if (matrix[i][j] >= 0) {
                    std::cout << " ";
                }
                std::cout << " " << matrix[i][j];
            }
            std::cout << std::endl;
        }
    }

    void print_matrix(std::vector< std::vector<bool> > matrix) {
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j]) {
                    std::cout << "1";
                } else {
                    std::cout << "0";
                }
            }
            std::cout << std::endl;
        }
    }


    void print_int_array(std::vector<int> array) {
        for (size_t i = 0; i < array.size(); i++) {
            std::cout << std::to_string(array.at(i)) + " ";
        }
        std::cout << std::endl;
    }

    std::string char_array_to_string(char* array) {
        std::string buffer{};
        for (size_t i = 0; array[i] != 0; i++) {
            buffer += array[i];
        }
        return buffer;
    }

    std::string list_of_points_to_string(std::vector<std::tuple<int, int>> list) {
        std::string buffer{};
        for (std::tuple<int, int> p : list) {
            buffer += "(" + std::to_string(std::get<0>(p)) + "," + std::to_string(std::get<1>(p)) + ")";
        }
        return buffer;
    }

    TreeNode<int> random_bst(size_t n, int min, int max) {
        int d = random_int_in_range(min, max);
        TreeNode<int> root(d);
        for (size_t i = 1; i < n; i++) {
            root.insert_in_order(random_int_in_range(min, max));
        }
        return root;
    }

    /* Creates tree by mapping the array left to right, top to bottom. */
    TreeNode<int> create_tree_from_array(std::vector<int> array) {
        return TreeNode<int>(array);
    }

    std::string get_long_text_blob() {
        std::string book = std::string("As they rounded a bend in the path that ran beside the river, Lara recognized the silhouette of a fig tree atop a nearby hill. The weather was hot and the days were long. The fig tree was in full leaf, but not yet bearing fruit. ")
                    + "Soon Lara spotted other landmarks�an outcropping of limestone beside the path that had a silhouette like a man�s face, a marshy spot beside the river where the waterfowl were easily startled, a tall tree that looked like a man with his arms upraised. They were drawing near to the place where there was an island in the river. The island was a good spot to make camp. They would sleep on the island tonight."
                    + "Lara had been back and forth along the river path many times in her short life. Her people had not created the path�it had always been there, like the river�but their deerskin-shod feet and the wooden wheels of their handcarts kept the path well worn. Lara�s people were salt traders, and their livelihood took them on a continual journey. ";
        std::replace(book.begin(), book.end(), '.', ' ');
        std::replace(book.begin(), book.end(), ',', ' ');
        std::replace(book.begin(), book.end(), '-', ' ');
        return book;
    }

    std::vector<std::string> get_long_text_blob_as_string_list() {
        std::istringstream iss{get_long_text_blob()};
        return std::vector<std::string> {std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};
    }

    std::vector<std::string> get_list_of_words() {
        // Words in the dictionary.
        std::vector<std::string> word_list{ "the", "of", "and", "a", "to", "in", "is", "be",
                            "that", "was", "world", "awesome", "he", "for", "it", "with",
                            "as", "his", "I", "on", "have", "at", "by", "not", "surely",
                            "they", "this", "attract", "computer", "had", "are", "but",
                            "from", "or", "she", "an", "which", "you", "one", "we", "all",
                            "were", "her", "would", "there", "their", "will", "when",
                            "who", "him", "been", "has", "more", "if", "no", "out", "do",
                            "so", "can", "what", "up", "said", "about", "other", "into",
                            "than", "its", "time", "only", "could", "new", "them", "man",
                            "some", "these", "then", "two", "first", "May", "any", "like",
                            "now", "my", "such", "make", "over", "our", "even", "most",
                            "me", "state", "after", "also", "made", "many", "did", "must",
                            "before", "back", "see", "through", "way", "where", "get",
                            "much", "go", "well", "your", "know", "should", "down", "work",
                            "year", "because", "come", "people", "just", "say", "each",
                            "those", "take", "day", "good", "how", "long", "Mr", "own",
                            "too", "little", "use", "us", "very", "great", "still", "men",
                            "here", "life", "both", "between", "old", "under", "last",
                            "never", "place", "same", "another", "think", "abuse", "house",
                            "while", "high", "right", "might", "came", "off", "find",
                            "states", "since", "used", "give", "against", "three",
                            "himself", "look", "few", "general", "heart", "hand", "school",
                            "resin", "part", "small", "American", "home", "during",
                            "number", "again", "Mrs", "around", "thought", "went",
                            "without", "however", "govern", "don't", "does", "got",
                            "public", "United", "point", "end", "become", "head", "once",
                            "course", "fact", "upon", "need", "system", "set", "every",
                            "trend", "war", "put", "form", "water", "took", "program",
                            "present", "government", "thing", "told", "possible", "group",
                            "large", "until", "always", "city", "didn't", "order", "away",
                            "called", "want", "eyes", "something", "unite", "going",
                            "face", "far", "asked", "interest", "later", "show", "knew",
                            "though", "less", "night", "early", "almost", "let", "open",
                            "enough", "side", "case", "days", "yet", "better", "nothing",
                            "tell", "problem", "toward", "given", "why", "national",
                            "room", "young", "social", "light", "business", "president",
                            "help", "power", "country", "next", "things", "word", "looked",
                            "real", "John", "line", "second", "church", "seem", "certain",
                            "big", "Four", "felt", "several", "children", "service",
                            "feel", "important", "rather", "name", "per", "among", "often",
                            "turn", "development", "developmentcomputer", "keep", "family", "seemed", "white",
                            "company", "mind", "members", "others", "within", "done",
                            "along", "turned", "god", "sense", "week", "best", "change",
                            "kind", "began", "child", "ever", "law", "matter", "least",
                            "means", "question", "act", "close", "mean", "leave", "itself",
                            "force", "study", "York", "action", "it's", "door",
                            "experience", "human", "result", "times", "run", "different",
                            "car", "example", "hands", "whole", "center", "although",
                            "call", "Five", "inform", "gave", "plan", "woman", "boy",
                            "feet", "provide", "taken", "thus", "body", "play", "seen",
                            "today", "having", "cost", "perhaps", "field", "local",
                            "really", "am", "increase", "reason", "themselves", "clear",
                            "I'm", "information", "figure", "late", "above", "history",
                            "love", "girl", "held", "special", "move", "person", "whether",
                            "college", "sure", "probably", "either", "seems", "cannot",
                            "art", "free", "across", "death", "quite", "street", "value",
                            "anything", "making", "past", "brought", "moment", "control",
                            "office", "heard", "problems", "became", "full", "near",
                            "half", "nature", "hold", "live", "available", "known",
                            "board", "effect", "already", "Economic", "money", "position",
                            "believe", "age", "together", "shall", "TRUE", "political",
                            "court", "report", "level", "rate", "air", "pay", "community",
                            "complete", "music", "necessary", "society", "behind", "type",
                            "read", "idea", "wanted", "land", "party", "class", "organize",
                            "return", "department", "education", "following", "mother",
                            "sound", "ago", "nation", "voice", "six", "bring", "wife",
                            "common", "south", "strong", "town", "book", "students",
                            "hear", "hope", "able", "industry", "stand", "tax", "west",
                            "meet", "particular", "cut", "short", "stood", "university",
                            "spirit", "start", "total", "future", "front", "low",
                            "century", "Washington", "usually", "care", "recent",
                            "evidence", "further", "million", "simple", "road",
                            "sometimes", "support", "view", "fire", "says", "hard",
                            "morning", "table", "left", "situation", "try", "outside",
                            "lines", "surface", "ask", "modern", "top", "peace",
                            "personal", "member", "minutes", "lead", "schools", "talk",
                            "consider", "gone", "soon", "father", "ground", "living",
                            "months", "therefore", "America", "started", "longer", "Dr",
                            "dark", "various", "finally", "hour", "north", "third", "fall",
                            "greater", "pressure", "stage", "expected", "secretary",
                            "needed", "That's", "kept", "eye", "values", "union",
                            "private", "alone", "black", "required", "space", "subject",
                            "english", "month", "understand", "I'll", "nor", "answer",
                            "moved", "amount", "conditions", "direct", "red", "student",
                            "rest", "nations", "heart", "costs", "record", "picture",
                            "taking", "couldn't", "hours", "deal", "forces", "everything",
                            "write", "coming", "effort", "market", "island", "wall",
                            "purpose", "basis", "east", "lost", "St", "except", "letter",
                            "looking", "property", "Miles", "difference", "entire", "else",
                            "color", "followed", "feeling", "son", "makes", "friend",
                            "basic", "cold", "including", "single", "attention", "note",
                            "cause", "hundred", "step", "paper", "developed", "tried",
                            "simply", "can't", "story", "committee", "inside", "reached",
                            "easy", "appear", "include", "accord", "Actually", "remember",
                            "beyond", "dead", "shown", "fine", "religious", "continue",
                            "ten", "defense", "getting", "Central", "beginning", "instead",
                            "river", "received", "doing", "employ", "trade", "terms",
                            "trying", "friends", "sort", "administration", "higher",
                            "cent", "expect", "food", "building", "religion", "meeting",
                            "ready", "walked", "follow", "earth", "speak", "passed",
                            "foreign", "NATURAL", "medical", "training", "County", "list",
                            "floor", "piece", "especially", "indeed", "stop", "wasn't",
                            "England", "difficult", "likely", "Suddenly", "moral", "plant",
                            "bad", "club", "needs", "international", "working",
                            "countries", "develop", "drive", "reach", "police", "sat",
                            "charge", "farm", "fear", "test", "determine", "hair",
                            "results", "stock", "trouble", "happened", "growth", "square",
                            "William", "cases", "effective", "serve", "miss", "involved",
                            "doctor", "earlier", "increased", "being", "blue", "hall",
                            "particularly", "boys", "paid", "sent", "production",
                            "district", "using", "thinking", "concern", "Christian",
                            "press", "girls", "wide", "usual", "direction", "feed",
                            "trial", "walk", "begin", "weeks", "points", "respect",
                            "certainly", "ideas", "industrial", "methods", "operation",
                            "addition", "association", "combine", "knowledge", "decided",
                            "temperature", "statement", "Yes", "below", "game", "nearly",
                            "science", "directly", "horse", "influence", "size", "showed",
                            "build", "throughout", "questions", "character", "foot",
                            "Kennedy", "firm", "reading", "husband", "doubt", "services",
                            "according", "lay", "stay", "programs", "anyone", "average",
                            "French", "spring", "former", "summer", "bill", "lot",
                            "chance", "due", "comes", "army", "actual", "Southern",
                            "neither", "relate", "rise", "evening", "normal", "wish",
                            "visit", "population", "remain", "measure", "merely",
                            "arrange", "condition", "decision", "account", "opportunity",
                            "pass", "demand", "strength", "window", "active", "deep",
                            "degree", "ran", "western", "E", "sales", "continued", "fight",
                            "heavy", "arm", "standard", "generally", "carry", "hot",
                            "provided", "serious", "led", "wait", "hotel", "opened",
                            "performance", "maybe", "station", "changes", "literature",
                            "marry", "claim", "works", "bed", "wrong", "main", "unit",
                            "George", "hit", "planning", "supply", "systems", "add",
                            "chief", "officer", "Soviet", "pattern", "stopped", "price",
                            "success", "lack", "myself", "truth", "freedom", "manner",
                            "quality", "gun", "manufacture", "clearly", "share",
                            "movement", "length", "ways", "burn", "forms", "Organization",
                            "break", "somewhat", "efforts", "cover", "meaning", "progress",
                            "treatment", "beautiful", "placed", "happy", "attack",
                            "apparently", "blood", "groups", "carried", "sign", "radio",
                            "dance", "I've", "regard", "man's", "train", "herself",
                            "numbers", "corner", "REACTION", "immediately", "language",
                            "running", "recently", "shake", "larger", "lower", "machine",
                            "attempt", "learn", "couple", "race", "audience", "Oh",
                            "middle", "brown", "date", "health", "persons",
                            "understanding", "arms", "daily", "suppose", "additional",
                            "hospital", "pool", "technical", "served", "declare",
                            "described", "current", "poor", "steps", "reported", "sun",
                            "based", "produce", "determined", "receive", "park", "staff",
                            "faith", "responsibility", "Europe", "latter", "British",
                            "season", "equal", "learned", "practice", "green", "writing",
                            "ones", "choice", "fiscal", "term", "watch", "scene",
                            "activity", "product", "types", "ball", "heat", "clothe",
                            "lived", "distance", "parent", "letters", "returned",
                            "forward", "obtained", "offer", "specific", "straight", "fix",
                            "division", "slowly", "shot", "poet", "seven", "moving",
                            "mass", "plane", "proper", "propose", "drink", "obviously",
                            "plans", "whatever", "afternoon", "figures", "parts",
                            "approve", "saying", "born", "immediate", "fame", "gives",
                            "extent", "justice", "cars", "mark", "pretty", "opinion",
                            "ahead", "glass", "refuse", "enter", "completely", "send",
                            "desire", "judge", "none", "waiting", "popular", "Democratic",
                            "film", "mouth", "Corps", "importance", "touch", "director",
                            "ship", "there's", "council", "EFFECTS", "event", "worth",
                            "existence", "designed", "hardly", "indicated", "analysis",
                            "established", "products", "growing", "patient", "rule",
                            "bridge", "pain", "base", "check", "cities", "elements",
                            "leaders", "discussion", "limited", "sit", "Thomas",
                            "agreement", "gas", "factors", "marriage", "easily", "closed",
                            "excite", "accept", "applied", "allow", "bit", "married",
                            "oil", "Rhode", "shape", "interested", "strange", "compose",
                            "professional", "remained", "news", "Despite", "beauty",
                            "responsible", "wonder", "spent", "tear", "unless", "eight",
                            "permit", "covered", "Negro", "played", "I'd", "vote",
                            "balance", "Charles", "loss", "Commission", "original", "fair",
                            "reasons", "studies", "exactly", "built", "behavior", "enemy",
                            "teeth", "bank", "die", "James", "relations", "weight",
                            "prepared", "related", "sea", "bar", "warn", "post", "trees",
                            "official", "separate", "clay", "Sunday", "raised", "events",
                            "thin", "dropped", "cattle", "invite", "playing", "prevent",
                            "detail", "standing", "grow", "places", "someone", "bright",
                            "Talking", "meant", "print", "capital", "happen", "sides",
                            "everyone", "facilities", "filled", "lip", "essential",
                            "techniques", "June", "knows", "stain", "hadn't", "dinner",
                            "dog", "dollars", "caught", "shout", "buy", "divide",
                            "entered", "Chicago", "speed", "jazz", "appoint", "governor",
                            "institutions", "fit", "materials", "sight", "store",
                            "dependence", "explain", "gain", "he'd", "leadership", "quiet",
                            "realize", "parents", "Communist", "neighbor", "round",
                            "included", "kitchen", "thousand", "Christ", "isn't",
                            "radiation", "broad", "stops", "failure", "retire", "election",
                            "primary", "king", "books", "command", "edge", "ember",
                            "March", "sitting", "conference", "bottom", "lady", "advise",
                            "churches", "model", "battle", "giving", "sport", "address",
                            "considerable", "spread", "funds", "trip", "youth",
                            "CONSTRUCTION", "rock", "regular", "changed", "boat", "memory",
                            "successful", "captain", "hell", "brother", "murder", "quick",
                            "moreover", "highly", "difficulty", "inch", "saw", "clean",
                            "collect", "camp", "experiment", "shows", "Authority", "older",
                            "lord", "variety", "material", "frame", "distinguish",
                            "scientific", "introduce", "principal", "Jack", "kill",
                            "collection", "fell", "entertain", "pieces", "management",
                            "otherwise", "security", "danger", "entirely", "civil",
                            "frequently", "advertise", "records", "secret", "title",
                            "impossible", "yesterday", "fast", "Mike", "produced", "favor",
                            "noted", "caused", "lose", "purposes", "solid", "song",
                            "corporation", "lie", "winter", "dress", "electric", "key",
                            "dry", "reduce", "fresh", "goes", "hill", "names", "slow",
                            "quickly", "telephone", "threaten", "oppose", "deliver",
                            "officers", "expression", "published", "famous", "pray",
                            "adopt", "London", "clothes", "laws", "citizens", "announced",
                            "minute", "master", "sharp", "advantage", "greatest",
                            "relation", "Mary", "leaving", "gray", "manager", "animal",
                            "object", "bottle", "draw", "honor", "recognize", "drop",
                            "intend", "relationship", "opposite", "sources", "poetry",
                            "ability", "assistance", "operating", "bear", "join", "climb",
                            "companies", "exist", "fixed", "gradual", "possibility",
                            "hunt", "spoke", "satisfy", "units", "neck", "sleep",
                            "doesn't", "finished", "carefully", "facts", "nice",
                            "practical", "save", "takes", "allowed", "wine", "remind",
                            "rich", "financial", "dream", "knife", "stations", "civilize",
                            "Rose", "cool", "died", "thick", "imagine", "literary", "bind",
                            "inches", "earn", "familiar", "seeing", "distribution",
                            "marked", "coffee", "rules", "slip", "apply", "page", "beside",
                            "daughter", "Relatively", "classes", "explore", "stated",
                            "German", "musical", "smile", "significant", "block", "mix",
                            "reports", "PROPOSED", "shelter", "presence", "Affairs",
                            "named", "ordinary", "circumstances", "mile", "sweep",
                            "remains", "admire", "Catholic", "dust", "operations", "rain",
                            "tree", "nobody", "Henry", "Robert", "village", "advance",
                            "offered", "agree", "mechanic", "upper", "occasion",
                            "requirements", "capacity", "appears", "travel", "article",
                            "houses", "valley", "beat", "opening", "box", "evil",
                            "succeed", "surround", "application", "slightly", "remembered",
                            "interests", "warm", "subjects", "search", "presented", "shoe",
                            "sweet", "interesting", "membership", "suggest", "notice",
                            "connection", "extreme", "exchange", "flow", "spend",
                            "everybody", "poems", "campaign", "win", "forced", "freeze",
                            "nine", "eat", "newspaper", "please", "escape", "lives",
                            "swim", "file", "wind", "provides", "shop", "apartment",
                            "fashion", "reasonable", "created", "Germany", "watched",
                            "cells", "session", "somehow", "fully", "whose", "teacher",
                            "raise", "recognized", "unity", "Providence", "reference",
                            "explained", "twenty", "Russian", "features", "shoulder",
                            "sir", "forest", "studied", "Sam", "signal", "chair",
                            "reduced", "procedure", "forth", "limit", "disturb",
                            "universe", "mentioned", "pick", "reality", "differences",
                            "soft", "traditional", "Mission", "flat", "looks", "picked",
                            "weather", "smaller", "leg", "chairman", "ancient", "narrow",
                            "fellow", "twist", "belief", "excellent", "rights",
                            "vocational", "laid", "politics", "fill", "response",
                            "struggle", "disappear", "prove", "duty", "FOLLOWS", "editor",
                            "welcome", "anode", "possess", "hearing", "BUILDINGS", "ideal",
                            "scientist", "formed", "watching", "circle", "ought", "garden",
                            "library", "accuse", "message", "slight", "junior", "knock",
                            "empty", "protection", "treated", "birth", "expressed",
                            "planned", "choose", "confuse", "Virginia", "killed",
                            "frighten", "stayed", "worry", "surprise", "aside",
                            "photograph", "removed", "turning", "Jr", "pull", "personnel",
                            "agency", "pointed", "speech", "listen", "November", "sample",
                            "Louis", "motor", "selected", "Berlin", "CLAIMS", "spot",
                            "strike", "increasing", "exercise", "handle", "hole", "Leader",
                            "baby", "ride", "avoid", "cross", "twice", "commercial",
                            "failed", "prompt", "fat", "fourth", "visitor", "interior",
                            "Jewish", "wing", "desk", "faculty", "forget", "operate",
                            "stair", "besides", "relief", "standards", "France", "perfect",
                            "pour", "Nevertheless", "brief", "Jones", "kick", "attend",
                            "plus", "solution", "wage", "individuals", "powers",
                            "minister", "taste", "discovered", "pulled", "hire", "writer",
                            "verb", "preach", "friendly", "observed", "fan", "connect",
                            "Fig", "count", "egg", "items", "mention", "Texas",
                            "calculate", "platform", "drag", "mere", "tomorrow", "faces",
                            "pure", "fighting", "resources", "increases", "assumed",
                            "broke", "coast", "strict", "whom", "Russia", "qualify",
                            "Morgan", "victory", "fields", "pleasure", "contain", "fold",
                            "review", "April", "teach", "Richard", "whisper", "chosen",
                            "metal", "PRINCIPLES", "competition", "railroad", "safe",
                            "proved", "carrying", "horses", "kiss", "Mercer", "wheel",
                            "sail", "wants", "compared", "relieve", "approximately",
                            "wood", "historical", "persuade", "smiled", "crowd", "motion",
                            "shore", "suit", "calls", "seat", "deserve", "San", "snow",
                            "double", "educational", "neighborhood", "relative",
                            "teachers", "Independent", "puzzle", "nose", "dogs", "waited",
                            "naturally", "stone", "origin", "Rome", "wild", "scale",
                            "tremble", "drawn", "guess", "communism", "absence", "roof",
                            "sections", "sky", "walls", "Aircraft", "complain",
                            "independence", "busy", "elect", "revolution", "roar",
                            "willing", "League", "mine", "nurse", "liberal", "completed",
                            "poem", "dollar", "ordered", "levels", "ton", "settled",
                            "allowance", "bitter", "realized", "let's", "moon",
                            "sensitive", "servant", "hunger", "China", "sale",
                            "appearance", "lips", "policies", "actions", "strengthen",
                            "Monday", "onto", "directed", "leading", "machinery",
                            "theater", "Paris", "Frank", "somewhere", "Statements", "mill",
                            "projects", "starting", "hat", "ruin", "depend", "stands",
                            "signs", "families", "stir", "Khrushchev", "largely", "punish",
                            "drew", "breathe", "amuse", "characteristic", "electronic",
                            "pale", "pictures", "destroy", "expense", "somebody",
                            "completion", "disappoint", "fifty", "found", "soil", "flame",
                            "enjoy", "bless", "emotional", "promise", "she'd", "wave",
                            "commerce", "Jury", "bay", "tempt", "correct", "asking",
                            "content", "estimated", "conscious", "shine", "teaching",
                            "catch", "dish", "Saturday", "greet", "background", "flood",
                            "insect", "worse", "yellow", "occurred", "afraid", "ceremony",
                            "decrease", "trust", "yourself", "legs", "you've",
                            "communication", "describe", "sincere", "decide", "leaf",
                            "encourage", "rub", "declared", "cry", "bite", "July", "lung",
                            "significance", "helped", "gross", "apart", "disease",
                            "issues", "scratch", "dictionary", "risk", "broadcast", "drum",
                            "representative", "uncle", "cutting", "Jesus", "neglect",
                            "depth", "substantial", "GETS", "adventure", "beg", "entrance",
                            "plays", "throw", "ends", "Arts", "alive", "confidence",
                            "intellectual", "cheer", "properties", "experiments", "nut",
                            "plenty", "beneath", "closely", "description", "melt", "swear",
                            "tall", "loose", "area", "bury", "measured", "request",
                            "ourselves", "stream", "wipe", "band", "fingers", "creature",
                            "Hanover", "attorney", "load", "passing", "billion", "earnest",
                            "discussed", "translate", "achievement", "headquarters",
                            "inquiry", "rapidly", "express", "hesitate", "guard", "jobs",
                            "borrow", "owe", "Phil", "California", "ambition", "supposed",
                            "lake", "they're", "slope", "Typical", "spite", "wore", "dear",
                            "employees", "map", "pair", "spin", "one's", "praise",
                            "imagination", "hung", "instrument", "plow", "holding",
                            "objects", "straighten", "dominant", "scarce", "ring",
                            "matters", "creep", "plain", "resolution", "credit", "period",
                            "improve", "maintenance", "seize", "Laos", "we'll", "dozen",
                            "located", "dig", "towards", "curse", "major", "breath",
                            "weigh", "comfort", "federal", "guests", "priest", "sell",
                            "bodies", "female", "primarily", "cousin", "grew", "spiritual",
                            "dine", "engine", "politician", "custom", "educate",
                            "individual", "job", "Tom", "cook", "grass", "mail",
                            "salesman", "nail", "tap", "wet", "bedroom", "sufficient",
                            "chest", "dramatic", "silence", "behave", "breakfast",
                            "sudden", "passage", "scatter", "objection", "unusual",
                            "argument", "policy", "powerful", "throat", "formal", "rapid",
                            "Parker", "wrap", "luck", "grind", "rifle", "HIGHEST", "loan",
                            "represent", "skill", "spell", "broken", "arch", "angle",
                            "sick", "swell", "blind", "Contemporary", "engineer",
                            "military", "boundary", "location", "homes", "boil",
                            "officials", "operator", "Senate", "lend", "hearts", "embers", "abused", "resins", "trendy", "ssdsy" };
        return word_list;
    }

    Trie get_trie_dictionary() {
        return Trie(get_list_of_words());
    }

    std::unordered_set<std::string> get_word_list_as_hash_set() {
        auto word_list = get_list_of_words();
        std::unordered_set<std::string> word_set;
        for (std::string s : word_list) {
            word_set.insert(s);
        }
        return word_set;
    }
}