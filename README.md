# Cal

2 Περιγραφή εργασίας

2.1 Ιουλιανό και Γρηγοριανό ημερολόγιο

Το Γρηγοριανό ημερολόγιο, προτάθηκε το 1582 για να αντικαταστήσει το Ιουλιανό ημερολόγιο. Ο κύριος
λόγος ήταν η τροποποίηση του τρόπου υπολογισμούς των ημερών του έτους ώστε να είναι πιο κοντά στη
διάρκεια περιστροφής της Γης γύρω από τον Ήλιο. Ο κανόνας του Ιουλιανού ημερολογίου είναι ότι κάθε 4
χρόνια ανεξαιρέτως έχουμε δίσεκτο έτος. Ο κανόνας για τα δίσεκτα έτη στο Γρηγοριανό ημερολόγιο είναι
ότι κάθε 4 χρόνια έχουμε δίσεκτο έτος, εκτός από όσα έτη διαιρούνται με 100. Εξαίρεση στον τελευταίο
κανόνα είναι όσα έτη διαιρούνται με το 400 (τα οποία είναι δίσεκτα). Έτσι για παράδειγμα το 1800 και το
1900 δεν είναι δίσεκτα έτη, ενώ το 2000 (που διαιρείται με το 400), είναι. Επιπλέον, κατά τη μετατροπή του
το Γρηγοριανό ημερολόγιο χρειάστηκε να προσθέσει κάποιες μέρες για να διορθώσει την απόκλιση που ήδη
είχε συσσωρευτεί, και έτσι την Πέμπτη, 4 Οκτωβρίου 1582 ακολούθησε η Παρασκευή, 15 Οκτωβρίου 1582.
Ωστόσο η υιοθέτηση του ημερολογίου αυτού συνεχίστηκε μέχρι το 1923, με την Ελλάδα να είναι η τελευταία
χώρα που το υιοθέτησε
Έχοντας συμβατότητα με την εντολή cal του UNIX, η εφαρμογή μας θα ακολουθεί το Ιουλιανό ημερολόγιο μέχρι τις 2 Σεπτεμβρίου 1752, με την επόμενη μέρα να είναι η 14η Σεπτεμβρίου 1752. Αυτές είναι
οι ημερομηνίες που το Γρηγοριανό ημερολόγιο υιοθετήθηκε από τη Βρετανική Κοινοπολιτεία. Από αυτή την
ημερομηνία και έπειτα το πρόγραμμά μας πρέπει να ακολουθεί το Γρηγοριανό ημερολόγιο.


2.2 Τύπος υπολογισμού

Έστω
• w είναι η μέρα της εβδομάδας από 0 (Σάββατο) έως 6 (Παρασκευή)
• d είναι η μέρα του μήνα (ξεκινώντας από το 1)
• m είναι ο μήνας (από 3 που είναι ο Μάρτιος μέχρι τον 14 που είναι ο Φεβρουάριος, έτσι ώστε ο
Φεβρουάριος να είναι ο τελευταίος μήνας)
• y είναι το έτος, ή το έτος μείον ένα, αν ο μήνας είναι Ιανουάριος ή Φεβρουάριος
Τότε στο Ιουλιανό ημερολόγιο η ημέρα της εβδομάδας δίνεται από τον παρακάτω τύπο

Έτσι για παράδειγμα για την 25/11/2024 έχουμε d = 25, m = 11, y = 2024 και το Γρηγοριανό ημερολόγιο επιστρέφει w = 2, δηλαδή ∆ευτέρα. Αντίστοιχα, για την 29/2/1584 σύμφωνα με το Ιουλιανό ημερολόγιο
ήταν w = 0, δηλαδή Σάββατο.
