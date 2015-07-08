#!/usr/bin/python2.7

# JSON lib
import json

# Lines of main.scene
flines = []

# Open scene.json
ifs = open('scene.json')

# Decode
decoded = json.load(ifs)

# Close scene.json
ifs.close()

# Generate main.scene lines
ecount = 0
ccount = 0
for prefab in decoded:
    instance = 'e%d' %ecount
    savetext = '%s *%s = ' %(prefab, instance)

    if len(decoded[prefab]) == 0:
        savetext = ''

    flines.append('%sgame.Instantiate<%s>();' %(savetext, prefab))

    for component in decoded[prefab]:
        if component == 'texture':
            path = decoded[prefab][component]
            flines.append('%s->SetTexture("%s");' %(instance, path))

        else:
            curComponent = 'c%d' %ccount
            flines.append('%s *%s = %s->GetComponent<%s>();' %(component, curComponent, instance, component))

            for attribute in decoded[prefab][component]:
                value = decoded[prefab][component][attribute]
                flines.append('%s->%s = %s;' %(curComponent, attribute, str(value)))

            ccount += 1

    if savetext != '':
        ecount += 1

# Create main.scene file
ofs = open('main.scene', 'w')

# Write into file
ofs.writelines([line + '\n' for line in flines])

# Close main.scene file
ofs.close()

