/*! \mainpage Thesauri Designer ver. 1.00
 *
 * \authors Piotr Batog, Michał Pichliński
 *
 * \section wstep Krótko o programie
 * Program jest przeglądarką i edytorem tezaurusów stworzonych w oparciu o język
 * opisowy SKOS. Został on stworzony w ramach pracy projektowej:
 * "Budowa i profilowanie modeli informacyjnych" z kursu Komputerowe
 * Przetwarzanie Informacji. Program jest napisany w "C++",  wykorzystuje 
 * biblioteki <A HREF="http://qt.nokia.com">Qt</A> oraz 
 * <A HREF="http://soprano.sourceforge.net/">Soprano RDF Framework</A>.
 *
 * \section inst Instalacja
 * \subsection dep Wymagane biblioteki:
 * Żeby zainstalować program potrzebne są następujące biblioteki: \n
 * - <A HREF="http://qt.nokia.com">Qt</A> w wersji 4.6.2
 * - <A HREF="http://soprano.sourceforge.net/">Soprano RDF Framework</A> w
 * wersji 2.5.3
 * \subsection start Uruchomienie instalatora
 * Należy przejść do katalogu w którym jest instalator (katalog główny programu)
 * następnie uruchomić skrypt instalacyjny: \n
 * $ ./Install.sh \n
 * Skrypt sprawdzi czy wymagane biblioteki są zainstalowane, jeśli będą
 * to skompiluje on program dając plik wykonywalny ThesauriDesigner w katalogu
 * głównym. Gdyby okazało się, że brakuje którejś z bibliotek instalator zwróci
 * informację o potrzebie instalacji brakujących rzeczy.
 *
 * \section features Możliwości programu
 * Program udostępnia użytkownikowi następujące możliwości: \n
 * - wczytanie/zapisanie pliku z tezurusem
 * - edycja tezaurusa
 * - przeglądanie tezaurusa
 * - przeszukiwanie tezaurusa
 * - automatyczne utrzymanie spójności tezaurusa
 *
 * \subsection files Obsługiwane pliki
 * Obsługiwane pliki są w formacie 
 * <A HREF="http://www.w3.org/TeamSubmission/turtle/">Turtle</A>, 
 * będący standardem <A HREF="http://www.w3.org/">W3C</A>. Zapisany
 * w pliku tezaurus powinien być opisany za pomocą języka 
 * <A HREF="http://www.w3.org/TR/2009/REC-skos-reference-20090818/">SKOS</A>.
 * Plik musi mieć poprawną składnię, ponieważ w przeciwnym wypadku nastąpi
 * wyjście z programu. W przypadku serializacji pliku nie ma prefiksowania
 * przestrzeni nazw, w związku z tym wszystkie URL konceptów są wypisywane w
 * całości
 *
 * \subsection auto Automatyczne utrzymanie spójności tezaurusa
 * Program przy dodawaniu relacji i konceptów, automatycznie sprawdza, czy
 * dane stwierdzenie jest spójne. Jeśli dodawane właściwości mogą spowodować
 * brak spójności wtedy próba wstawienia do tezaurusa danego stwierdzenia
 * zostaje odrzucona. Również, podczas wczytywania plików jeśli plik będzie
 * naruszała relacje wtedy pominie ona dodawanie ich do modelu.
 */
