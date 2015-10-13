/*Генератора кода для задания от яндекса.
Задание улучшить этот код
class CodeGenerator
{
public:
    enum Lang {JAVA, C_PLUS_PLUS, PHP};
    CodeGenerator(Lang language) { _language=language; }
    std::string generateCode()
    {
        switch(_language) {
        case JAVA:        //return generated java code
        case C_PLUS_PLUS: //return generated C++ code
        case PHP:         //return generated PHP code
        }
        throw new std::logic_error("Bad language");
    }
    std::string someCodeRelatedThing() // used in generateCode()
    {
        switch(_language) {
        case JAVA:        //return generated java-related stuff
        case C_PLUS_PLUS: //return generated C++-related stuff
        case PHP:         //return generated PHP-related stuff
        }
        throw new std::logic_error("Bad language");
    }

private:
    Lang _language;
}


Ошибки дизайна:
1. Алгоритм поиска со сложностью O(n)
2. Добавление нового языка требует изменение минимум 2-х методов.
3. Нарушение инкапсуляции, класс выше генерирует код для всех языков, что не хорошо.

Исправления:
1. применив std::map <lang_name, pointer_to_generation_method> - получим логарифмическую сложность
2. вынести генерацию кода в отдельные объекты.
    Тут возможны варианты
    1) — используем наследование от интерфейса LangGen, - но получаем жесткую связь в виде наследования; - это если необходимый функционал точно не будет меняться, но так не бывает. Если задачу решать в общем виде — то наследование не вариант.
    2) — Лучше не иметь жесткой связи — решением станет использованием указателя не метод класса который генерирует код для конкретного языка, а в конфигурации генератора указать модули конкретных языков. Для добавления нового языка надо будет: 1) разработать новый модуль генерации и 2) добавить его в конфиг.
copyright Boris Rozhkin borisrozhkin@gmail.com
*/


#include <iostream>
#include <functional>
#include <string>
#include <map>
using namespace std;

class Java
{
    public:
	string gen() {return "Generate Java code";}
	string name() const {return "Java";}
};	


class PHP
{
    public:
	string gen() {return "Generate PHP code";}
	string name() const {return "PHP";}
};	

class Lisp
{
    public:
	string gen() {return "(Generate Lisp code)";}
	string name() const {return "Lisp";}
};	


class Generator
{
	Generator(){ cout <<"+one generator" << endl;}
	Generator( Generator const&);
	Generator& operator=( Generator const& );
	Generator( Generator const&&);
	Generator& operator=( Generator const&& );
	~Generator(){ cout <<"-one generator" << endl;}

	typedef std::map <string, function<string()> > Langs;
	Langs map_; 
    public:	
	static Generator& Instance() {static Generator single_; return single_;}
	/*return frue if new lang generator has added, overwise return false*/
	bool append_lang( string const& _name, function<string(void)> _func )
	{
	    return map_.insert( make_pair(_name, _func ) ).second;
	}
	
	string generate_code( string const& _lang ) throw(string)
	{	
	    auto gen_iter = map_.find( _lang );
	    if ( gen_iter != map_.end() )
		return gen_iter->second();
	    string err = "No generator for lang \"" + _lang + "\"";
	    throw err;
	}
};

Generator& get_gen() {return Generator::Instance();}

template <class T>
bool gen_append_lang( T const& _t )
{
    return get_gen().append_lang( _t.name(), std::bind(&T::gen, _t) );
}

string generate( string _lang )
{
    return get_gen().generate_code( _lang );
}

int main( int argc, char** argv )
{

    //Generator& gen = get_gen();

    Java java_gen;
    PHP php_gen;
    Lisp lisp_gen;

    cout <<  "Add Java" <<  (gen_append_lang( java_gen ) ? " - success" : " - already added" ) << endl;
    cout <<  "Add PHP" <<  (gen_append_lang( php_gen ) ? " - success" : " - already added" ) << endl;
    cout <<  "Add Lisp" <<  (gen_append_lang( lisp_gen ) ? " - success" : " - already added" ) << endl;
    cout <<  "Add Java" <<  (gen_append_lang( java_gen ) ? " - success" : " - already added" ) << endl;
    
    cout << "-------------------------------" << endl;
    try
    {
	cout << generate( java_gen.name() ) << endl;
	cout << generate( "Lisp" ) << endl;

	cout << generate( "Ada" ) << endl;
	
    }
    catch ( string s )
    {
	cout << "!!! Error :: " << s << endl; 
    }	
    return 0;
}


