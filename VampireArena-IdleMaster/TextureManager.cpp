#include "TextureManager.h"

TextureManager::TextureManager()
{
	defaultTexturePath = "MissingTexture";
	defaultTextureExtension = "png";
	defaultTexture = nullptr;
}

TextureManager::~TextureManager()
{
	delete defaultTexture;
}

void TextureManager::LoadDefaultTexture()
{
	const string& _finalPath = defaultTexturePath + "." + defaultTextureExtension;
	defaultTexture = new Texture();
	LoadTexture(*defaultTexture, _finalPath);
}

void TextureManager::LoadTexture(Texture& _texture, const string& _path, const IntRect& _rect)
{
	const string& _finalPath = "Assets/Textures/" + _path;
	if (!_texture.loadFromFile(_finalPath, false, _rect))
	{
		cerr << "Error => Cannot open file path with the following path : \'" + _path + "\' !" << endl;
		_texture = GetDefaultTexture();
	}
}

void TextureManager::SetTexture(Shape* _shape, const Texture* _texture)
{
	_shape->setTexture(_texture);
}

void TextureManager::Load(ShapeActor* _shapeActor, const string& _path, const IntRect& _rect, const bool _isRepeated, const bool _smooth)
{

	Texture& _texture = _shapeActor->GetTexture();
	if (_path.empty())
	{
		cerr << "Error => Cannot open file with an following path !" << endl;
		_texture = GetDefaultTexture();
		SetTexture(_shapeActor->GetDrawable(), &_texture);
		return;
	}

	// Init Texture
	LoadTexture(_texture, _path);
	_texture.setRepeated(_isRepeated);
	_texture.setSmooth(_smooth);

	// Apply Texture
	SetTexture(_shapeActor->GetDrawable(), &_texture);
}

