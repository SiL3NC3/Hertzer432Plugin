/*
  ==============================================================================

	This file was auto-generated!

	It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SoundTouchPlugAudioProcessorEditor :
	public juce::AudioProcessorEditor,
	public juce::Button::Listener,
	public juce::Slider::Listener
{
public:
	SoundTouchPlugAudioProcessorEditor(SoundTouchPlugAudioProcessor&);
	~SoundTouchPlugAudioProcessorEditor();

	//==============================================================================
	SoundTouchPlugAudioProcessor& processor;

	void paint(juce::Graphics& g) override;
	void resized() override;
	void buttonClicked(juce::Button* buttonThatWasClicked);
	void sliderValueChanged(juce::Slider* sliderThatWasMoved);

	// Binary resources:
	static const char* background_png;
	static const int background_pngSize;
	static const char* buttonoff_png;
	static const int buttonoff_pngSize;
	static const char* buttonon_png;
	static const int buttonon_pngSize;
	static const char* wiRsymbolwhite_svg;
	static const int wiRsymbolwhite_svgSize;
	static const char* hertzerLogo_png;
	static const int hertzerLogo_pngSize;

private:
	// This reference is provided as a quick way for your editor to
	// access the processor object that created it.
	std::unique_ptr<juce::ImageButton> juce__imageButton;
	std::unique_ptr<juce::Slider> juce__slider;
	std::unique_ptr<juce::Label> juce__label2;
	std::unique_ptr<juce::ToggleButton> juce__toggleButton;
	std::unique_ptr<juce::HyperlinkButton> juce__hyperlinkButton;
	std::unique_ptr<juce::Label> juce__label3;
	std::unique_ptr<juce::HyperlinkButton> juce__hyperlinkButton2;
	std::unique_ptr<juce::Label> juce__label;
	std::unique_ptr<juce::Label> juce__label4;
	std::unique_ptr<juce::HyperlinkButton> juce__hyperlinkButton3;
	juce::Image cachedImage_background_png_1;
	juce::Image cachedImage_hertzerLogo_png_2;
	std::unique_ptr<juce::Drawable> drawable3;

	void initialize();
	void update();

	std::unique_ptr<float> last_semitones;

	//juce::AudioParameterBool* m_par_enabled = nullptr;
	//juce::AudioParameterFloat* m_par_semitones = nullptr;
	//juce::Label* m_label = nullptr;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundTouchPlugAudioProcessorEditor)
};
