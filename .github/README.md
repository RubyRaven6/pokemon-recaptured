# Pokémon Recaptured


## Team Credits
<!---You only get to add yourself once you're done with the game, Ruby--->
* miriamlefae - EXP code

## Special Thanks
- miriamlefae
- mudskipper13
- Montblanc

## Expansion Features Utilized
- Gen 4+ Pokémon
- Overworld Pokémon Sprites
- Mega Evolution
- HGSS Pokédex
- Forced Saving
- Dynamic Multichoice

## Credits
- pokeemerald-expansion
- Kris Sprites by [EndlessTGX](https://www.deviantart.com/endlesstgx/art/Crystal-Sprites-704463782)
- FRLG-styled Hoenn Tilesets: 
  - Jaizu
  - Citrus Bolt
  - TheDeadHeroAlistair
  - Poffin_Case. 
  - Special thanks: Syreldar
- SwSH User Interfaces Feature Branch by: Montblanc
  <details>
  <summary>Complete Credits for Summary Screen, Party Menu, Storage System, Bag Menu, Message Box</summary>
  <ul>
  <li> Summary Screen
    <ul>
      <li> RavePossum (BW summary screen)
      <li> Vexx (auto-format code)
      <li> Buffelsaft (IV/EV code)
      <li> Dizzyegg (nature color code)
      <li> Zeturic (wrapping summary screen)
      <li> Greenphx9 (pokefirered reference)
      <li> Skeli (heart indicator graphic, based on Unbound)
      <li> Zatsu (Tera type icons)
    </ul>
  <li> Party Menu
    <ul>
      <li> RavePossum (animated mon sprite code from BW summary screen)
      <li> Kasen (item multi-use for medicine, exp/rare candies, EV items/berries)
      <li> hedara (idea of sprite text printing on transparent window and sprite 1 priority below)
      <li> Archie (comfy_anim spam)
      <li> ShantyTown (for actually creating comfy_anim) - kudos to ruby for reminding me
      <li> Doodle (idea to animate item switching)
    </ul>
  <li> Storage System
    <ul>
      <li> Zatsu (helped me get alpha blend working in move items/chooseboxmon modes)
      <li> hedara (for pointing out, in an unrelated context, that the battle interface uses BG y-offsets, which I leveraged for the mon info panel)
    </ul>
  <li> Bag Menu
    <ul>
      <li> ShantyTown (coding comfy_anim) and Archie (spreading the gospel of comfy_anim)
      <li> Kasen (item multi use code, borrowed from party menu)
      <li> Zatsu (visual feedback) and PCG (playtesting)
    </ul>
  <li> Message Box
  </ul>
  </details>

- SWSH Style Stat Editor
  - Feature Branch: PCG
  - Archie: Base stat editor
  - BlackFragrant: SwSh style graphics
  - Montblanc: SwSh icons
  - Zatsu: Tera type icons
- Quest Menu Features
  - Quest Icons by: Belle
  - Quest Menu Feature Branch by PSF
    <details>
    <summary>Full Quest Menu Credits</summary>
    <ul>
    <li><a href="https://www.youtube.com/channel/UCRIShSkz-VJWqQT83KQlNjg">Skeli#3917</a>
        <ul>
        <li>Developed the original Unbound menu
        <li>Provided a variant of the current background
        <li>Provided an implementation of fading text
        <li>Suggested ways to reduce the size of quests on saveblock2
        </ul>
    <li><a href="https://www.pokecommunity.com/member.php?u=581824">ghoulslash#3839</a>
        <ul>
        <li>[Developed the original Quest Menu](https://www.pokecommunity.com/showthread.php?t=434462)
        <li>Helped debug adding a new macro to vanilla
        <li>Helped debug object priority for sprite creation
        <li>Provided bitwise operation for removing quest status
        </ul>
    <li>HN (PSF Developer): A lot of these aren't written down because we meet in voice calls, but HN was instrumental in getting this working.
    <li><a href="https://github.com/SBird1337/">Karathan#1337</a>
        <ul>
        <li>Explained printing encoded strings via MgbaPrintf 
        <li>Suggested ways to reduce the size of quests on saveblock2
        <li>Suggested ways to allocate memory for prepending/append of the quest name
        <li>Helped debug adding the UI background and palette
        </ul>
    <li><a href="https://github.com/atasro2/pwaa1">MCboy#0891</a>
        <ul>
        <li>Helped debug and refactor the implementation of fading text
        <li>Suggested ways to fix the object fading issue
        </ul>
    <li><a href="https://github.com/Greenphx9">Greenphx#5428</a>: Ported this feature to pokefirered
    <li><a href="https://www.pokecommunity.com/member.php?u=471077">MGriffin#3997</a> / <a href="https://www.pokecommunity.com/member.php?u=22062">Deokishisu#3251</a>: Suggested ways to reduce the size of quests on saveblock2
    <li><a href="https://github.com/nielsmittertreiner">BSBob#4144</a>: Provided implementation for prepending/append of the quest name
    <li>MM (PSF Developer)
        <ul>
        <li>Pointed out that the W stood for Wumbo.
        <li>Proofread this documentation
        </ul>
    <li><a href="https://raymie.xyz/">Raymie Humbert</a>: Designed the banner header
    <li>missiri#4895: Provided two alternate backgrounds
    <li><a href="https://github.com/tustin2121">Tustin2121</a>: Fixed the object fading issue
    <li><a href="https://github.com/ravepossum">RavePossum</a>: Updated branch to properly build when using modern compiler
    <li><a href="https://steamcommunity.com/profiles/76561198116557987">RAP Yogurt</a>: Found a typo in the documentation
    </ul>
    </details>