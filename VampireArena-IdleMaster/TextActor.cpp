#include "TextActor.h"

TextActor::TextActor(string _fontName,string _text, u_int _charSize)
{
	Font _font = Font(_fontName);
	text = new Text(_font, _text, _charSize);
}

TextActor::~TextActor()
{
	delete text;
}
