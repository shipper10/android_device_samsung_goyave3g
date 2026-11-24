#!/usr/bin/env python3
"""Remove SELinux extended-permission (ioctl xperm) rules from policy sources.

Policy version 30 is needed for allowxperm/neverallowxperm. The stock SM-T116
3.10.17 kernel only accepts policy versions 15-28 ("Could not load policy:
Invalid argument" -> init reboots into recovery), so when building for that
kernel the xperm rules must be dropped and checkpolicy run with -c 28.

Usage: strip_xperm.py DIR [DIR...]   (idempotent)
"""
import os, re, sys

START = re.compile(r'^\s*(allowxperm|neverallowxperm|auditallowxperm|dontauditxperm)\b')

def strip(path):
    lines = open(path, encoding='utf-8', errors='surrogateescape').read().split('\n')
    out, skipping, removed = [], False, 0
    for ln in lines:
        if skipping or START.match(ln):
            removed += 1
            # a statement ends at the first ';' outside of a comment
            skipping = ';' not in ln.split('#', 1)[0]
            continue
        out.append(ln)
    if removed:
        open(path, 'w', encoding='utf-8', errors='surrogateescape').write('\n'.join(out))
    return removed

total = 0
for root in sys.argv[1:]:
    for dp, _, fs in os.walk(root):
        for f in fs:
            if f.endswith('.te') or f in ('ioctl_macros', 'global_macros', 'te_macros', 'neverallow_macros'):
                n = strip(os.path.join(dp, f))
                if n:
                    print('%s: removed %d line(s)' % (os.path.join(dp, f), n))
                    total += n
print('total removed: %d' % total)
