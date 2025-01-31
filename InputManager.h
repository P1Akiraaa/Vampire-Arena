#pragma once
#include "CoreMinimal.h"
#include "Singleton.h"

namespace Input
{
	using KeyPressed = Event::KeyPressed;
	using Code = Keyboard::Key;
	using Clicked = Mouse::Button;
	using Click = Event::MouseButtonPressed;
	using Close = Event::Closed;

	struct InputData
	{
		vector<Code> codes;
		bool isAnyKey;
		function<void()> callback;

		InputData(const function<void()> _callback, const vector<Code> _codes, const bool _isAnyKey = false)
		{
			callback = _callback;
			codes = _codes;
			isAnyKey = _isAnyKey;
		}

		FORCEINLINE bool TryToExecute(const KeyPressed* _key)
		{
			if (!isAnyKey && !ContainsKey(_key->code)) return false;

			callback();
			return true;
		}

		FORCEINLINE bool ContainsKey(const Code& _currentCode) const
		{
			for (const Code& _code : codes)
			{
				if (_currentCode == _code) return true;
			}

			return false;
		}
	};

	struct ClickData
	{
		Clicked click;
		function<void()> callback;

		ClickData(const function<void()> _callback, const Clicked* _mouse, const bool _isAnyButton = false)
		{
			callback = _callback;
			click = *_mouse;
		}

		FORCEINLINE bool TryToExecute(const Click* _click)
		{
			if (!(click == _click->button)) return false;
			callback();
			return true;
		}

	};
	class InputManager : public Singleton<InputManager>
	{
		vector<InputData> inputsData;
		vector<ClickData> clickData;

	public:
		void ConsumeInput(RenderWindow& _window);
		void BindAction(const function<void()>& _callback, const Code& _code);
		void BindAction(const function<void()>& _callback, const  Clicked& _click);
		void BindAction(const function<void()>& _callback, const vector<Code>& _codes = {});

	private:
		void CloseWindow(RenderWindow& _window);
	};
}