#include "InputManager.h"

namespace Input
{
	void InputManager::ConsumeInput(RenderWindow& _window)
	{
		while (const optional _event = _window.pollEvent())
		{
			if (_event->is<Close>())
			{
				_window.close();
			}

			else if (const KeyPressed* _key = _event->getIf<KeyPressed>())
			{
				for (InputData& _inputData : inputsData)
				{
					if (_inputData.TryToExecute(_key)) break;
				}
			}

			else if (const Click* _key = _event->getIf<Click>())
			{
				for (ClickData& _clickData : clickData)
				{
					if (_clickData.TryToExecute(_key)) break;
				}
			}
		}
	}

	void InputManager::BindAction(const function<void()>& _callback, const Code& _code)
	{
		inputsData.push_back(InputData(_callback, { _code }));
	}

	void InputManager::BindAction(const function<void()>& _callback, const Clicked& _click)
	{
		clickData.push_back(ClickData(_callback, &_click));
	}

	void InputManager::BindAction(const function<void()>& _callback, const vector<Code>& _codes)
	{
		inputsData.push_back(InputData(_callback, _codes, _codes.empty()));
	}

	void InputManager::CloseWindow(RenderWindow& _window)
	{
		_window.close();
	}
}