#include <Hazel.h>

#include "imgui/imgui.h"

class ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//HZ_INFO("ExampleLayer::Update");

		if (Hazel::Input::IsKeyPressed(HZ_KEY_TAB))
		{
			HZ_TRACE("Tab key is pressed (poll)!");
		}
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello, world!");
		ImGui::End();
	}

	void OnEvent(Hazel::Event& event) override
	{
		//HZ_TRACE("{0}", event);
		if (event.GetEventType() == Hazel::EventType::KeyPressed)
		{
			Hazel::KeyPressedEvent& e = (Hazel::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HZ_KEY_TAB)
			{
				HZ_TRACE("Tab key is pressed (event)!");
			}
		}
	}

};

class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{
	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}