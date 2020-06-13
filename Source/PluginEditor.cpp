/*
  ==============================================================================

	This file was auto-generated!

	It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
ExpansorStereoAudioProcessorEditor::ExpansorStereoAudioProcessorEditor(ExpansorStereoAudioProcessor& p)
	: AudioProcessorEditor(&p), processor(p)
{

	// Make sure that before the constructor has finished, you've set the
	// editor's size to whatever you need it to be.
	setSize(600, 400);

	//Botón Threshold
	threshold.setSliderStyle(Slider::SliderStyle::Rotary);
	threshold.setRange(-20.0f, 20.0f, 1);
	threshold.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
	threshold.setTextValueSuffix(" dB");
	threshold.setValue(0.0);
	threshold.addListener(this);

	//Botón Width
	width.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
	width.setRange(0.0f, 1.0f, 0.01);
	width.setValue(0.5);
	width.setTextValueSuffix(" %");
	width.addListener(this);

	//Botón Release
	release.setSliderStyle(Slider::SliderStyle::Rotary);
	release.setRange(0.0f, 5.0f, 1);
	release.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
	release.setTextValueSuffix(" s");
	release.setValue(0.0);
	release.addListener(this);

	//Botón Attack
	attack.setSliderStyle(Slider::SliderStyle::Rotary);
	attack.setRange(0.0f, 1.0f, 0.1);
	attack.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
	attack.setTextValueSuffix(" s");
	attack.setValue(0.0);
	attack.addListener(this);

	//Botón Pan
	pan.setSliderStyle(Slider::SliderStyle::Rotary);
	pan.setRange(0.0f, 1.0f, 0.1);
	pan.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
	pan.setValue(0.5);
	pan.setTextValueSuffix(" L-R");
	pan.addListener(this);

	//Botón Ratio
	ratio.setSliderStyle(Slider::SliderStyle::Rotary);
	ratio.setRange(1.0f, 10.0f, 1);
	ratio.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
	ratio.setTextValueSuffix(" : 1");
	ratio.setValue(2.0);
	ratio.addListener(this);

	//Botones añadidos
	addAndMakeVisible(&threshold);
	addAndMakeVisible(&width);
	addAndMakeVisible(&release);
	addAndMakeVisible(&attack);
	addAndMakeVisible(&pan);
	addAndMakeVisible(&ratio);

}

ExpansorStereoAudioProcessorEditor::~ExpansorStereoAudioProcessorEditor()
{
}

//==============================================================================
void ExpansorStereoAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
	//Se identifica el slider
	if (slider == &width) {
		processor.widthPerc = width.getValue();//se guarda el valor del slider en la variable del processors
	}
	else if (slider == &threshold) {
		processor.thresholddB = threshold.getValue();
	}
	else if (slider == &release) {
		processor.getParams().release = release.getValue();
		processor.release = release.getValue();//quitar
	}
	else if (slider == &attack) {
		processor.getParams().attack = attack.getValue();
		processor.vAttack = attack.getValue();//quitar
	}
	else if (slider == &pan) {
		processor.pan = pan.getValue();
	}
	else if (slider == &ratio) {
		processor.vRatio = ratio.getValue();
	}
}

void ExpansorStereoAudioProcessorEditor::paint(Graphics& g)
{
	// (Our component is opaque, so we must completely fill the background with a solid colour)

	auto th = Rectangle<int>(20, 90, 110, 110);
	auto re = Rectangle<int>(130, 90, 110, 110);
	auto at = Rectangle<int>(250, 90, 110, 110);
	auto pa = Rectangle<int>(370, 90, 110, 110);
	auto ra = Rectangle<int>(480, 90, 110, 110);
	auto wd = getLocalBounds().removeFromBottom(getWidth() / 4);

	// fill the whole window 
	g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

	// set the current drawing colour to black
	g.setColour(Colours::white);

	// set the font size and draw text to the screen
	g.setFont(15.0f);

	g.drawFittedText("Threshold", th, Justification::centredTop, 1);
	g.drawFittedText("Release", re, Justification::centredTop, 1);
	g.drawFittedText("Attack", at, Justification::centredTop, 1);
	g.drawFittedText("Pan", pa, Justification::centredTop, 1);
	g.drawFittedText("Ratio", ra, Justification::centredTop, 1);
	g.drawFittedText("Width", wd, Justification::centred, 1);

}

void ExpansorStereoAudioProcessorEditor::resized()
{
	// This is generally where you'll want to lay out the positions of any
	// subcomponents in your editor..
	// sets the position and size of the slider with arguments (x, y, width, height)

	auto th = Rectangle<int>(20, 100, 110, 110);
	auto re = Rectangle<int>(130, 100, 110, 110);
	auto at = Rectangle<int>(250, 100, 110, 110);
	auto pa = Rectangle<int>(370, 100, 110, 110);
	auto ra = Rectangle<int>(480, 100, 110, 110);

	Rectangle<int> bottom = getLocalBounds().removeFromBottom(getWidth() / 5);
	threshold.setBounds(th);
	release.setBounds(re);
	attack.setBounds(at);
	pan.setBounds(pa);
	ratio.setBounds(ra);
	width.setBounds(bottom);
}
