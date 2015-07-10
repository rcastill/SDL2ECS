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
tcount = 0
for prefab in decoded:
    for instance in decoded[prefab]:
        instanceName = 'e%d' %ecount
        savetext = '%s *%s = ' %(prefab, instanceName)

        if len(instance) == 0:
            savetext = ''

        flines.append('%sgame.Instantiate<%s>();' %(savetext, prefab))

        for component in instance:
            if component == 'texture':
                path = instance[component]
                flines.append('%s->SetTexture("%s");' %(instanceName, path))

            elif component == 'transform':
                curTransform = 't%d' %tcount
                flines.append('Transform &%s = %s->GetTransform();' %(curTransform, instanceName))

                for attribute in instance[component]:
                    value = instance[component][attribute]
                    flines.append('%s.%s = %s;' %(curTransform, attribute, str(value)))

                tcount += 1

            else:
                curComponent = 'c%d' %ccount
                flines.append('%s *%s = %s->GetComponent<%s>();' %(component, curComponent, instanceName, component))

                for attribute in instance[component]:
                    value = instance[component][attribute]
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

