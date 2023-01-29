/*
  ==============================================================================

	This file was auto-generated!

	It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SoundTouchPlugAudioProcessorEditor::SoundTouchPlugAudioProcessorEditor(SoundTouchPlugAudioProcessor& p)
	: AudioProcessorEditor(&p), processor(p)
{

	m_par_enabled = new juce::AudioParameterBool{ "enable","Enabled",true };
	m_par_semitones = new juce::AudioParameterFloat{ "shift","Semitones",-24.0,24.0,-4.0 };
	processor.addParameter(m_par_enabled);
	processor.addParameter(m_par_semitones);

	m_label = new juce::Label("Hertzer432");
	m_label->setBounds(1, 1, 100, 20);
	addAndMakeVisible(m_label);


	// Make sure that before the constructor has finished, you've set the
	// editor's size to whatever you need it to be.
	setSize(400, 300);
}

SoundTouchPlugAudioProcessorEditor::~SoundTouchPlugAudioProcessorEditor()
{
}

//==============================================================================
void SoundTouchPlugAudioProcessorEditor::paint(juce::Graphics& g)
{
	// (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

	g.setColour(juce::Colours::white);
	g.setFont(15.0f);
	g.drawFittedText("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void SoundTouchPlugAudioProcessorEditor::resized()
{
	// This is generally where you'll want to lay out the positions of any
	// subcomponents in your editor..
}
