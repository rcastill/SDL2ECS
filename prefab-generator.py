#!/usr/bin/python2.7

# JSON library
import json

# prefabs.hh lines
flines = [
        '#include "api/include/entity.h"',
        '#include "ccomponents.hh"'
]

# Open prefabs.json file
ifs = open('prefabs.json')

# Decode file content
decoded = json.load(ifs)

# Close prefabs.json file
ifs.close()

# Generate lines
for entity in decoded:
    flines.append('class ' + entity + ' : public Entity {')
    flines.append('public:')
    flines.append('%s() {' %entity)

    for component in decoded[entity]:
        flines.append('AddComponent<%s>();' %component)

    flines.append('}};')

# Create prefabs.hh file
ofs = open('prefabs.hh', 'w')

# Write lines to file
ofs.writelines([line + '\n' for line in flines])

# Close prefabs.hh file
ofs.close()

