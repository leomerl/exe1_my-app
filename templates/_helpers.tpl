{{- define "hello.labels" -}}
app.kubernetes.io/name: {{ include "hello.name" . }}
app.kubernetes.io/instance: {{ .Release.Name }}
app.kubernetes.io/version: {{ .ChartAppVersion }}
app.kubernetes.io/managed-by: {{ .Release.Service }}
{{- end}}
