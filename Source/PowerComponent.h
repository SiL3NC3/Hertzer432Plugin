/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.4

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
	An auto-generated component, created by the Projucer.

	Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PowerComponent  : public juce::AudioProcessorEditor,
                        public juce::Button::Listener,
                        public juce::Slider::Listener
{
public:
    //==============================================================================
    PowerComponent (SoundTouchPlugAudioProcessor& p);
    ~PowerComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	SoundTouchPlugAudioProcessor& processor;

    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;

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
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::ImageButton> juce__imageButton;
    std::unique_ptr<juce::Slider> juce__slider;
    std::unique_ptr<juce::Label> juce__label2;
    std::unique_ptr<juce::ToggleButton> juce__toggleButton;
    std::unique_ptr<juce::HyperlinkButton> juce__hyperlinkButton;
    std::unique_ptr<juce::Label> juce__label3;
    std::unique_ptr<juce::HyperlinkButton> juce__hyperlinkButton2;
    std::unique_ptr<juce::Label> juce__label;
    juce::Image cachedImage_background_png_1;
    juce::Image cachedImage_hertzerLogo_png_2;
    std::unique_ptr<juce::Drawable> drawable3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PowerComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

