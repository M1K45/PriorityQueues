#include "extract_measure.hpp"
#include "insert_measure.hpp"
#include "modify_measure.hpp"
#include "peek_measure.hpp"
#include "size_measure.hpp"
#include "wizualizacja.hpp"


	
int main() {
	int wybor;

    std:: cout << "=================================\n";
    std::cout << "\tCo chcesz zrobic?\n";
    std:: cout << "=================================\n\n";

    std::cout << "1) Wyswietlic drivier\n";
    std::cout << "2) Przeprowadzic badania (wszystkie naraz, wyniki zostana zapisane do pliku CSV)\n";

    std::cout << "Wpisz liczbe odpowiadajaca Twojej decycji: "; std::cin >> wybor;
	
	 switch (wybor)
    {
    case 1:
    {
        wizualizacja();
        break;
    }

    case 2:
    {
        for (int i = 10000; i <= 80000; i += 10000){
            ArrayInsertMeasure(i);
        }
		for (int i = 10000; i <= 80000; i += 10000){
            HeapInsertMeasure(i);
        }


		for (int i = 10000; i <= 80000; i += 10000){
            ArrayExtractMeasure(i);
        }
		for (int i = 10000; i <= 80000; i += 10000){
            HeapExtractMeasure(i);
        }


		for (int i = 10000; i <= 80000; i += 10000){
            ArrayModifyMeasure(i);
        }
		for (int i = 10000; i <= 80000; i += 10000){
            HeapModifyMeasure(i);
        }


		for (int i = 10000; i <= 80000; i += 10000){
            ArrayPeekMeasure(i);
        }
		for (int i = 10000; i <= 80000; i += 10000){
            HeapPeekMeasure(i);
        }


		for (int i = 10000; i <= 80000; i += 10000){
            ArraySizeMeasure(i);
        }
		for (int i = 10000; i <= 80000; i += 10000){
            HeapSizeMeasure(i);
        }

        break;
    }

    default:
	{
        std::cout << "Wybierz liczbę sposrod podanych.\n";
        break;
    }
	}







    return 0;
}
