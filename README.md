
## Design Principles

1. Addons adhere to community best practices as represented by CBA.
2. Code should be as transparent as possible, intuitive to even the greenest modder.
3. Where transparency is impossible, document the hell out of it in clear and concise language.
4. Write code now to save code later. Aim to develop a comprehensive set of highly configurable modules that any mission creator may use to avoid burdensome SQF diversions. 

## Goals

Vanquish is built as an independent mod with a tight coupling to ALiVE. For most intents and purposes, you may think of it as an "extension" to ALiVE though it has no affiliation with that mod's development. Vanquish depends on ALiVE because it has a proven track record of simulating believable conflicts and force dispositions at an unparalleled scale. It also represents one of the most reliable unit virtualization solutions the community has at our disposal. The way Vanquish interacts with ALiVE is outlined later on in this readme, but it can best be summarized like this:

>  Alive does an excellent job of creating a conflict "aquarium" in that it efficiently simulates the behaviours of a hierarchical command structure orchestrating high-level troop movements. You can even dive into the "aquarium" and have the units interact with you in immersive and believable ways. 
> 
> What Vanquish aims to do is help your everyday hobbyist mission creator turn that "aquarium" into an episode of _Planet Earth_. We want to empower mission creators to build structured narratives, compelling objects and fulfilling reward systems all set against the vivid and lifelike backdrop that ALiVE offers.

## Architecture

### File Structure
The mod is organized into a series of interdependent addons representing specific domains of functionality. CBA refers to these domains as "components" and we do as well. 