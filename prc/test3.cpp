/*
copyright Boris Rozhkin borisrozhkin@gmail.com
*/

#include <vector>
#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

class Feature
{
	std::vector <double> points_; // раз есть методы рисования которые переопределяются в потомках - незачем открывать потомкам массив точек
	enum FeatureType {eUnknown=0, eCircle, eTriangle, eSquare};
	std::map <FeatureType, int> pn {{eUnknown,0}, {eCircle, 3}, {eTriangle, 6}, {eSquare, 8} };

    protected:
	virtual void drawPoligon( double* _points, int _size )
	{
	    cout << "Рисую полигон по точкам: ";
	    for( int i = 0; i < _size; ++i )
		cout << _points[i] << " ";
	    cout << endl;
	}

	virtual void drawCircle( double X, double Y, double R )
	{
	    cout << "Рисую круг центр: " << X << ":"<< Y << " radius: " << R << endl;
	}
	FeatureType type_;
    public:
	Feature( ) : type_( eUnknown )    
	{
	}
	bool isValid()
	{
	    return type_;
	}    
	bool read( FILE* file )
	{
	    FeatureType type;
	    if (fread(&type, sizeof(type), 1, file ) != sizeof(type) ) return false;
	    auto fig_code_iter = pn.find( type );
	    if ( fig_code_iter == pn.end() ) return false;
	    type_ = fig_code_iter->first;
	    points_.resize( fig_code_iter->second );
	    return fread( points_.data(), sizeof(double), fig_code_iter->second, file ) == sizeof( double )*fig_code_iter->second;  	    
	}
	void draw()
	{
	    //т.к. методы рисования примитивов(круга и полигона) описаны в секции протектед значит еще где то переопределяются
	    // сл-но сигнатуру методов менять нельзя, потому массив указателей на методы не заюзать(требуется одинаковая сигнатура) - поэтому код ниже оставляем также как и был
	    switch( type_ ) 
	    {
		case eTriangle:
		case eSquare:
		    drawPoligon( points_.data(), points_.size() );
		    break;
		case eCircle:
		    drawCircle ( points_[0], points_[1], points_[2] );
		    break;
		default: cerr << "!!! Error :: Фигура не указана" << endl;
	    }
	}

};
int main( int argc, char** argv )
{
    Feature feature;
    FILE* file = fopen("feature.dat", "r");
    if ( file )
    {
	feature.read( file );
	if ( !feature.isValid() ) return 1;
    }
    return 0;
}

