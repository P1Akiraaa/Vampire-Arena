#pragma once
#include "Actor.h"
#include "RenderType.h"
namespace UI
{
	// Permet de mettre le type de visibilité
	enum VisibilityType
	{
		Hidden, // Caché
		Collapsed, // Reduit mais pas caché
		Disabled, 
		UninteractibleSelf, // Interagissable 
		UninteractibleSelfAndChildren, // Interagissable et ces enfants
		Visible,

	};


	class Widget : public Actor
	{
		RenderType type;
		VisibilityType visibility;
		u_int renderToken;
		int zOrder;

	public:
	public:
		FORCEINLINE void SetVisibility(const VisibilityType& _visibility)
		{
			visibility = _visibility;
		}

		/// <summary>
		/// Z order permet de donner l'ordre d'affichage
		/// IMPORTANT il n'est pas définie de base
		///	!!! Il faut appeler la méthode avant Construct() !!!
		/// </summary>
		/// <param name="_zOrder"></param>
		FORCEINLINE void SetZOrder(const int _zOrder)
		{
			zOrder = _zOrder;
		}

	public:
		Widget(const string& _name, const RenderType& _type = Screen);

		virtual void Construct() override;
		virtual void Deconstruct() override;

		/// <summary>
		/// Important pour faire des widgets on utilise les classes fille
		/// étant donner que la classe est virtuelle pure
		/// </summary>
		/// <param name="_window"></param>
		virtual void Render(RenderWindow& _window) = 0;
	};
}


