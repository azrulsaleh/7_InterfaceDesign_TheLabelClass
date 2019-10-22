/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
	addAndMakeVisible(titleLabel);
	titleLabel.setFont(Font(16.0f, Font::bold));
	titleLabel.setText("Click in the white box to enter some text...", dontSendNotification);
	titleLabel.setColour(Label::textColourId, Colours::lightgreen);
	titleLabel.setJustificationType(Justification::centred);

	addAndMakeVisible(inputLabel);
	inputLabel.setText("Text input:", dontSendNotification);
	inputLabel.attachToComponent(&inputText, true);
	inputLabel.setColour(Label::textColourId, Colours::orange);
	inputLabel.setJustificationType(Justification::right);

	addAndMakeVisible(inputText);
	inputText.setEditable(true);
	inputText.setColour(Label::backgroundColourId, Colours::darkblue);
	inputText.setColour(Label::outlineWhenEditingColourId, Colours::orangered);
	inputText.onTextChange = [this] 
	{ 
		uppercaseText.setText(inputText.getText().toUpperCase(), dontSendNotification);
		lowercaseText.setText(inputText.getText().toLowerCase(), dontSendNotification);
	};
	inputText.onEditorShow = [this]
	{
		auto editorFont = inputText.getCurrentTextEditor()->getFont();
		editorFont.setItalic(true);
		inputText.getCurrentTextEditor()->setFont(editorFont);
	};

	addAndMakeVisible(uppercaseLabel);
	uppercaseLabel.setText("Uppercase:", dontSendNotification);
	uppercaseLabel.attachToComponent(&uppercaseText, true);
	uppercaseLabel.setColour(Label::textColourId, Colours::orange);
	uppercaseLabel.setJustificationType(Justification::right);
	
	addAndMakeVisible(uppercaseText);
	uppercaseText.setEditable(true);
	uppercaseText.setColour(Label::backgroundColourId, Colours::darkblue);

	addAndMakeVisible(lowercaseLabel);
	lowercaseLabel.setText("Lowercase:", dontSendNotification);
	lowercaseLabel.attachToComponent(&lowercaseText, true);
	lowercaseLabel.setColour(Label::textColourId, Colours::orange);
	lowercaseLabel.setJustificationType(Justification::right);

	addAndMakeVisible(lowercaseText);
	lowercaseText.setEditable(true);
	lowercaseText.setColour(Label::backgroundColourId, Colours::darkblue);

	addAndMakeVisible(clearButton);
	clearButton.setButtonText("CLEAR");
	clearButton.onClick = [this] 
	{ 
		inputText.setText("", dontSendNotification); 
		uppercaseText.setText("", dontSendNotification);
		lowercaseText.setText("", dontSendNotification);
	};

	addAndMakeVisible(infoLabel);
	String infoText;
	infoText << "This simple application takes some text input from the user, ";
	infoText << "converts it to uppercase, and displays this in another label. ";
	infoText << "The application demonstrates a number of useful features of the Label class.";
	infoLabel.setText(infoText, dontSendNotification);
	infoLabel.setColour(Label::backgroundColourId, Colours::darkblue);

	setSize (320, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    g.fillAll (Colours::black);
}

void MainComponent::resized()
{
	titleLabel.setBounds(10, 10, getWidth() - 20, 30);
	inputText.setBounds(100, 50, getWidth() - 110, 20);
	uppercaseText.setBounds(100, 80, getWidth() - 110, 20);
	lowercaseText.setBounds(100, 110, getWidth() - 110, 20);
	clearButton.setBounds(0, 140, getWidth(), 20);
	infoLabel.setBounds(10, 170, getWidth() - 20, getHeight() - 200);
}
